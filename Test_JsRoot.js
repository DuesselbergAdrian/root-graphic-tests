//IMPORTS
const rootSys = process.env.ROOTSYS;
const path_jsroot = `${rootSys}/js/modules/main.mjs`;
const { version, parse, makeSVG } = await import(path_jsroot);

import { promises as fs } from 'fs';
import path from 'path';
import xmlParser from 'xml-parser-xo';
import chalk from 'chalk';

// JSROOT version
console.log(chalk.blue(`JSROOT version ${version}`));

//FUNCTIONS

/**
 * Checks if two objects are equal by comparing their JSON string representations.
 * @param {Object} obj1 - The first object to compare.
 * @param {Object} obj2 - The second object to compare.
 * @returns {boolean} - True if the objects are equal, false otherwise.
 */
function isEqual(obj1, obj2) {
    return JSON.stringify(obj1) === JSON.stringify(obj2);
}

/**
 * Compares two SVG files, creating a reference file if the second file does not exist.
 * @param {string} svgContent1 - The content of the first SVG.
 * @param {string} svgContent2 - The content of the second SVG.
 * @param {string} baseName - The base name for logging.
 */
async function compareSVG(svgContent1, svgContent2, baseName) {
    try {
        const parsedSVG1 = xmlParser(svgContent1);
        const parsedSVG2 = xmlParser(svgContent2);

        if (isEqual(parsedSVG1, parsedSVG2)) {
            console.log(chalk.green(`MATCH: ${baseName} - Lengths [Pro: ${svgContent1.length}, Ref: ${svgContent2.length}]`));
        } else {
            console.error(chalk.red(`DIFF: ${baseName} - Lengths [Pro: ${svgContent1.length}, Ref: ${svgContent2.length}]`));
            throw Error;
        }
    } catch (error) {
        throw error;
    }
}
/**
* Creates an SVG from a JSON file.
* @param {string} filePath - The path to the JSON file.
* @returns {Promise<boolean>} - True if SVG creation and comparison are successful, false otherwise.
*/
async function createSVGFromJSON(filePath) {
    const baseName = path.basename(filePath, path.extname(filePath));
    const svgRefPath = `./svg_ref/${baseName}.svg`;
    const svgProPath = `./build/svg_pro/${baseName}_pro.svg`;

    try {
        // Read and parse JSON data
        const jsonData = await fs.readFile(filePath, 'utf8');
        const data = JSON.parse(jsonData);

        // Create SVG from parsed data
        let obj = parse(data);
        let svgPro = await makeSVG({ object: obj, option: 'lego2,pal50', width: 1200, height: 800 });

        // Check if reference SVG file exists
        try {
            await fs.access(svgRefPath);
            const svgRef = await fs.readFile(svgRefPath, 'utf8');

            // Save the produced SVG file
            await fs.writeFile(svgProPath, svgPro);

            // Compare the produced SVG with the reference SVG
            if (compareSVG(svgPro, svgRef, baseName)) {
                return true;
            } else {
                // Overwrite the reference SVG file with the produced one
                await fs.writeFile(svgRefPath, svgPro);
                console.log(chalk.yellow("Reference SVG file updated"));
                return false;
            }
        } catch (error) {
            if (error.code === 'ENOENT') {
                // Reference file does not exist, create a new one
                await fs.writeFile(svgRefPath, svgPro);
                console.log("Create a new reference file");
                return false;
            } else {
                throw error;
            }
        }
    } catch (error) {
        console.error(chalk.red('Failed to process JSON file:'), error);
    }
}

/**
 * Main function to run the tests.
 */
async function main() {
    const macro = process.argv[2];
    if (!macro) {
        console.error(chalk.red('No macro specified'));
        process.exit(1);
    }

    const jsonFilePath = `./json_ref/${macro}.json`;
    try {
        const success = await createSVGFromJSON(jsonFilePath);
        if (!success) {
            process.exit(1);
        }
    } catch (error) {
        console.error(chalk.red('Error in main function:'), error);
        process.exit(1);
    }
}


// Run the main function
main().catch(error => {
    console.error(chalk.red('Error in main function:'), error);
    process.exit(1);
});