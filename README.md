## Running root-graphics-tests

Our project includes two types of tests: one written in C++ using the ROOT framework and CTest and the other written in JavaScript using JSRoot and Node.js. Below are the instructions to run the tests. To run the tests, you need to have ROOT installed on your system. ROOT is a framework for data processing, developed by CERN. If you do not have ROOT installed, please visit the [ROOT Installation Guide](https://root.cern/install/) for installation instructions.

### C++ Test with ROOT generated JSON files:
The first test in the Test_JSON.cpp file creates TCanvas objects using ROOT macros. These TCanvas objects are then used to generate JSON files, which are saved in the json_pro folder. The generated JSON files are then compared to reference JSON files located in the json_ref folder.

### JavaScript Test with JSROOT generated SVG files:
The second test in the Test_SVG.js file generates SVG files using JSROOT based on the reference JSON files in the json_ref folder. These generated SVG files are saved in the svg_pro folder and are then compared during the test execution to ensure they match the expected output.

#### Running the Tests in root-graphic-tests:
```shell
cd build
ctest
```


