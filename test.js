import { promises as fs } from 'fs';
import { version, parse, makeSVG } from 'jsroot';
import path from 'path';

console.log(`JSROOT version ${version}`);

// FUNCTIONS

async function createSVGFromJSON(filePath) {
    try {
        //Read and parse the JSON file
        const jsonData = await fs.readFile(filePath, 'utf8');
        const data = JSON.parse(jsonData);

        // Assuming the JSON data is directly usable or needs minimal transformation
        let obj = parse(data);  // This step might need customization

        // Extract the base filename without extension
        const baseName = path.basename(filePath, path.extname(filePath));

        // Use JSROOT to create an SVG
        let svg = await makeSVG({ object: obj, option: 'lego2,pal50', width: 1200, height: 800 });

        // Write the SVG to a file
        const outputFileName = `${baseName}.svg`;
        fs.writeFile(outputFileName, svg);
        console.log(`Created ${outputFileName} size ${svg.length}`);
    } catch (error) {
        console.error('Failed to read, parse, or render the file:', error);
    }
}



//TESTS

createSVGFromJSON('./graphtext.json');
createSVGFromJSON('./piechart.json');
