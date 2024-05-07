// IMPORTS
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

        // Parse XML content of SVG files
        const parsedSVG1 = xmlParser(svgContent1);
        const parsedSVG2 = xmlParser(svgContent2);

        // Compare the parsed SVG objects
        if (isEqual(parsedSVG1, parsedSVG2)) {
            console.log(`${baseName} SVG files: MATCH`);
        } else {
            console.log(`${baseName} SVG files: DIFF`);
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
        let svg = await makeSVG({ object: obj, option: 'lego2,pal50', width: 1200, height: 800 });

        // Write to an SVG file
        await fs.writeFile(outputFileName, svg);
        //console.log(`Created ${outputFileName} size ${svg.length}`);

        // Compare
        const svgFileRef = `./svg_ref/${baseName}.svg`;
        await compareSVG(outputFileName, svgFileRef, baseName);
    } catch (error) {
        console.error('Failed to read, parse, or render the file:', error);
    }
}

// TESTS
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