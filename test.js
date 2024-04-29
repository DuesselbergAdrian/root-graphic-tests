import { promises as fs } from 'fs';
import { version, parse, makeSVG } from 'jsroot';

console.log(`JSROOT version ${version}`);

async function createSVGFromJSON(filePath) {
    try {
        // Step 1: Read and parse the JSON file
        const jsonData = await fs.readFile(filePath, 'utf8');
        const data = JSON.parse(jsonData);

        // Step 2: Assuming the JSON data is directly usable or needs minimal transformation
        // This is a placeholder; transform data as needed for JSROOT
        let obj = parse(data);  // This step might need customization

        // Step 3: Use JSROOT to create an SVG
        let svg = await makeSVG({ object: obj, option: 'lego2,pal50', width: 1200, height: 800 });

        // Step 4: Write the SVG to a file
        fs.writeFile('graphtext.svg', svg);
        console.log(`Created graphtext.svg size ${svg.length}`);
    } catch (error) {
        console.error('Failed to read, parse, or render the file:', error);
    }
}

createSVGFromJSON('./graphtext.json');