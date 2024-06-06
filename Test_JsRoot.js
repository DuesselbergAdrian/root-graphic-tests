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
 * @param {string} svgFile2 - The path to the second SVG file.
 * @param {string} baseName - The base name for logging.
 */
async function compareSVG(svgContent1, svgFile2, baseName) {
    try {
        const svgContent2 = await fs.readFile(svgFile2, 'utf8');
        const parsedSVG1 = xmlParser(svgContent1);
        const parsedSVG2 = xmlParser(svgContent2);

        if (isEqual(parsedSVG1, parsedSVG2)) {
            console.log(chalk.green(`MATCH: ${baseName} - Lengths [Pro: ${svgContent1.length}, Ref: ${svgContent2.length}]`));
        } else {
            console.error(chalk.red(`DIFF: ${baseName} - Lengths [Pro: ${svgContent1.length}, Ref: ${svgContent2.length}]`));
            throw Error;
        }
    } catch (error) {
        const outputFileName = `svg_ref/${baseName}.svg`;
        await fs.writeFile(outputFileName, svgContent1);
        console.error(chalk.red(`New reference file created: ${outputFileName}`));
        throw Error;
    }
}
/**
* Creates an SVG from a JSON file.
* @param {string} filePath - The path to the JSON file.
* @returns {Promise<boolean>} - True if SVG creation and comparison are successful, false otherwise.
*/
async function createSVGFromJSON(filePath) {
    const baseName = path.basename(filePath, path.extname(filePath));

    try {
        const jsonData = await fs.readFile(filePath, 'utf8');
        const data = JSON.parse(jsonData);

        let obj = parse(data);
        let svg_pro = await makeSVG({ object: obj, option: 'lego2,pal50', width: 1200, height: 800 });

        const svg_ref = `./svg_ref/${baseName}.svg`;

        if(compareSVG(svg_pro, svg_ref, baseName)){return true};
        return false;
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