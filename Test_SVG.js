/* IMPORTS
import { promises as fs, readFileSync } from 'fs';
import { version, parse, makeSVG } from 'jsroot';
import path from 'path';
import xmlParser from 'xml-parser-xo';

console.log(`JSROOT version ${version}`);

// FUNCTIONS

// Function to deeply compare two objects
function isEqual(obj1, obj2) {
    // Convert objects to JSON strings for comparison
    const str1 = JSON.stringify(obj1);
    const str2 = JSON.stringify(obj2);
    // Compare JSON strings
    return str1 === str2;
}

// Function to compare the content of two SVG files
async function compareSVG(svgFile1, svgFile2, baseName) {
    try {

        // Read SVG files
        const svgContent1 = await fs.readFile(svgFile1, 'utf8');
        const svgContent2 = await fs.readFile(svgFile2, 'utf8');

        // Get lengths
        const length_svgFile1 = svgContent1.length;
        const length_svgFile2 = svgContent2.length;

        // Parse XML content of SVG files
        const parsedSVG1 = xmlParser(svgContent1);
        const parsedSVG2 = xmlParser(svgContent2);

        // Compare the parsed SVG objects
        if (isEqual(parsedSVG1, parsedSVG2)) {
            console.log(`${baseName} SVG files: MATCH -> Length_Pro: ${length_svgFile1} Length_Ref: ${length_svgFile2}`);
        } else {
            console.log(`${baseName} SVG files: DIFF  -> Length_Pro: ${length_svgFile1} Length_Ref: ${length_svgFile2}`);
        }
    } catch (error) {
        console.error(`Failed to compare ${baseName} SVG files:`, error);
    }
}

async function createSVGFromJSON(filePath) {
    // Extract the base filename without extension
    const baseName = path.basename(filePath, path.extname(filePath));
    
    // Get file name
    const outputFileName = `svg_pro/${baseName}_pro.svg`;
    try {
        // Read and parse the JSON file
        const jsonData = await fs.readFile(filePath, 'utf8');
        const data = JSON.parse(jsonData);

        // Assuming the JSON data is directly usable or needs minimal transformation
        let obj = parse(data);  // This step might need customization

        // Use JSROOT to create an SVG
        let svg_pro = await makeSVG({ object: obj, option: 'lego2,pal50', width: 1200, height: 800 });

        // Write to an SVG file
        await fs.writeFile(outputFileName, svg_pro);
        //console.log(`Created ${outputFileName} size ${svg.length}`);

        // Get reference file
        const svg_ref = `./svg_ref/${baseName}.svg`;

        // Compare
        await compareSVG(outputFileName, svg_ref, baseName);
    } catch (error) {
        console.error('Failed to read, parse, or render the file:', error);
    }
}*/


import { promises as fs } from 'fs';
import { version, parse, makeSVG } from 'jsroot';
import path from 'path';
import xmlParser from 'xml-parser-xo';
import chalk from 'chalk';

console.log(chalk.blue(`JSROOT version ${version}`));

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
            console.log(chalk.red(`DIFF: ${baseName} - Lengths [Pro: ${svgContent1.length}, Ref: ${svgContent2.length}]`));
        }
    } catch (error) {
        console.error(chalk.red(`Error comparing ${baseName} SVG files:`), error);
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

        await compareSVG(outputFileName, svg_ref, baseName);
    } catch (error) {
        console.error(chalk.red('Failed to process JSON file:'), error);
    }
}

// Tutorial Graphic TESTS
console.log("Starting graphics tests...");
createSVGFromJSON('./build/test/json_ref/analyze.json');
createSVGFromJSON('./build/test/json_ref/archi.json');
createSVGFromJSON('./build/test/json_ref/arrows.json');
createSVGFromJSON('./build/test/json_ref/basic3d.json');
createSVGFromJSON('./build/test/json_ref/compile.json');
createSVGFromJSON('./build/test/json_ref/crown.json');
createSVGFromJSON('./build/test/json_ref/ellipse.json');
createSVGFromJSON('./build/test/json_ref/eval.json');
createSVGFromJSON('./build/test/json_ref/event.json');
createSVGFromJSON('./build/test/json_ref/feynman.json');
createSVGFromJSON('./build/test/json_ref/first.json');
createSVGFromJSON('./build/test/json_ref/formula1.json');
createSVGFromJSON('./build/test/json_ref/framework.json');
createSVGFromJSON('./build/test/json_ref/gaxis.json');
createSVGFromJSON('./build/test/json_ref/gaxis3.json');
createSVGFromJSON('./build/test/json_ref/greyscale.json');
createSVGFromJSON('./build/test/json_ref/latex.json');
createSVGFromJSON('./build/test/json_ref/latex2.json');
createSVGFromJSON('./build/test/json_ref/latex3.json');
createSVGFromJSON('./build/test/json_ref/latex4.json');
createSVGFromJSON('./build/test/json_ref/latex5.json');
createSVGFromJSON('./build/test/json_ref/markerwarning.json');
createSVGFromJSON('./build/test/json_ref/mass_spectrum.json');
createSVGFromJSON('./build/test/json_ref/pavetext.json');
createSVGFromJSON('./build/test/json_ref/piechart.json');
createSVGFromJSON('./build/test/json_ref/quarks.json');
createSVGFromJSON('./build/test/json_ref/tmathtext.json');
createSVGFromJSON('./build/test/json_ref/tmathtext2.json');
console.log("Graphics tests completed.");

// Tutorial Graphs TESTS
console.log("Starting graph tests...");
createSVGFromJSON('./build/test/json_ref/graph.json');
console.log("Graph tests completed.");