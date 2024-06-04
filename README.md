## Running root-graphics-tests

Our project includes two types of tests: one written in C++ using the ROOT framework and CTest and the other written in JavaScript using JSRoot and Node.js. Below are the instructions to run the tests. To run the tests, you need to have ROOT installed on your system. ROOT is a framework for data processing, developed by CERN. If you do not have ROOT installed, please visit the [ROOT Installation Guide](https://root.cern/install/) for installation instructions.

### C++ Test with ROOT generated files:
The first test in the Test_Root.cpp file creates TCanvas objects using ROOT macros. These TCanvas objects are then used to generate JSON/SVG files, which ate then compared to reference JSON/SVG files located in the json_ref/old_svg_ref folder.

### JavaScript Test with JSROOT generated SVG files:
The second test in the Test_JsRoot.js file generates SVG files using JSROOT based on the reference JSON files in the json_ref folder. These generated SVG files are then compared during the test execution to ensure they match the expected output.

### Running the Tests in root-graphic-tests:
```shell
cd build
ctest
```


