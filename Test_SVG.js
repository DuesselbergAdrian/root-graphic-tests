//IMPORTS
const rootSys = process.env.ROOTSYS;
const path1 = `${rootSys}/js/modules/main.mjs`;
const { version, parse, makeSVG } = await import(path1);

import { promises as fs } from 'fs';
import path from 'path';

import xmlParser from 'xml-parser-xo';
import chalk from 'chalk';

// JSROOT version
console.log(chalk.blue(`JSROOT version ${version}`));

//FUNCTIONS
function isEqual(obj1, obj2) {
    const str1 = JSON.stringify(obj1);
    const str2 = JSON.stringify(obj2);
    return str1 === str2;
}

async function compareSVG(svgFile1, svgFile2, baseName) {
    try {
        const svgContent1 = await fs.readFile(svgFile1, 'utf8');
        const svgContent2 = await fs.readFile(svgFile2, 'utf8');

        const parsedSVG1 = xmlParser(svgContent1);
        const parsedSVG2 = xmlParser(svgContent2);

        if (isEqual(parsedSVG1, parsedSVG2)) {
            console.log(chalk.green(`MATCH: ${baseName} - Lengths [Pro: ${svgContent1.length}, Ref: ${svgContent2.length}]`));
        } else {
            throw new Error(`DIFF: ${baseName} - Lengths [Pro: ${svgContent1.length}, Ref: ${svgContent2.length}]`);
        }
    } catch (error) {
        console.error(chalk.red(`Error comparing ${baseName} SVG files:`), error);
        throw error; 
    }
}

async function createSVGFromJSON(filePath) {
    const baseName = path.basename(filePath, path.extname(filePath));
    const outputFileName = `svg_pro/${baseName}_pro.svg`;

    try {
        const jsonData = await fs.readFile(filePath, 'utf8');
        const data = JSON.parse(jsonData);

        let obj = parse(data);
        let svg_pro = await makeSVG({ object: obj, option: 'lego2,pal50', width: 1200, height: 800 });

        await fs.writeFile(outputFileName, svg_pro);
        const svg_ref = `./svg_ref/${baseName}.svg`;

        if(compareSVG(outputFileName, svg_ref, baseName)){return true};
        return false;
    } catch (error) {
        console.error(chalk.red('Failed to process JSON file:'), error);
    }
}

// Main function to run the tests
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

main().catch(error => {
    console.error(chalk.red('Error in main function:'), error);
    process.exit(1);
});