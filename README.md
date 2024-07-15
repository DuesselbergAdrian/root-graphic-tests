## Running root-graphics-tests

Our project includes two types of tests: one written in C++ using the ROOT framework and CTest and the other written in JavaScript using JSRoot and Node.js. Below are the instructions to run the tests. To run the tests, you need to have ROOT installed on your system. ROOT is a framework for data processing, developed by CERN. If you do not have ROOT installed, please visit the [ROOT Installation Guide](https://root.cern/install/) for installation instructions.

### C++ Test with ROOT generated files:
The first test in the Test_Root.cpp file creates TCanvas objects using ROOT macros. These TCanvas objects are then used to generate JSON/SVG files, which ate then compared to reference JSON/SVG files located in the json_ref/old_svg_ref folder.

### JavaScript Test with JSROOT generated SVG files:
The second test in the Test_JsRoot.js file generates SVG files using JSROOT based on the reference JSON files in the json_ref folder. These generated SVG files are then compared during the test execution to ensure they match the expected output.

### Checkout repository
To start using the project, clone the repository to your local machine:
```shell
git clone https://github.com/DuesselbergAdrian/root-graphic-tests.git
cd root-graphic-tests
```
### Install dependencies
Install all necessary dependencies using npm:
```shell
npm install
```
### Prepare and run test
To prepare and run tests, ensure you have the required node packages installed in the root/js directory.
```shell
mkdir build
cd build
cmake ..
make
ctest
```

### Running specific tests
You can use ctest with various options to run specific tests. Below are some examples:
#### Running a single test
To run a specific test for a macro with a particular test type:
```shell
ctest -R macroname_ALL_testtype
```
Important: Replace macroname and testype

#### Running All Tests for a Single Macro
To run all tests for a specific macro:
```shell
ctest -R macroname_ALL
```
Important: Replace macroname

#### Running Tests for a Specific Macro Folder
To run all tests within a specific macro folder:
```shell
ctest -R macrofolder
```
Important: Replace macrofolder


### Checking Differences in Reference and Generated Files (git diff or diff)
Important: Both ways can be implemented but not at the same time.

#### Git diff (Implemented)
When comparing generated and reference files using git diff, you can directly observe changes when a test fails and the reference file is overwritten. It's crucial to note that certain parts of the files should be considered separately, as they are not part of standard comparison algorithms:

 - JSON Files: fTsumwx, ftsumwx2
 - Old SVG Files: <title> and <desc> sections
 - PDF files: creationDate-, modDate-, title- and xrefPattern

For detailed information please have a look at the PREPROCESSCONTENT functions.

#### Diff (Not implemented)
To check differences between generated and reference jsons one can use diff in the root-graphics-tests repository. These files are saved in the folders json_pro and json_ref.
```shell
diff builddir/json_pro/macroname_pro.json json_ref/macroname.json
```
Important: Replace macroname and builddir

To check differences between new generated and reference svgs one can use diff root-graphics-tests repository. These files are saved in the folders svg_pro and svg_ref.
```shell
diff builddir/svg_pro/macroname_pro.svg svg_ref/macroname.svg
```
Important: Replace macroname and builddir

To check differences between old generated and refernece svgs one can use diff in the root-graphics-tests repository. These files are saved in the folders old_svg_pro and old_svg_ref.
```shell
diff builddir/old_svg_pro/macroname_pro.svg old_svg_ref/macroname.svg
```
Important: Replace macroname and builddir

To check differences between old generated and refernece pdfs one can use diff in the root-graphics-tests repository. These files are saved in the folders pdf_pro and pdf_ref.
```shell
diff builddir/pdf_pro/macroname_pro.pdf pdf_ref/macroname.pdf
```
Important: Replace macroname and builddir


### Updating Reference Files
To update reference files if there are changes, delete the corresponding reference files and run the test twice. (Note: This process is not yet automated.)


### Adding New Tests
For instructions on how to add new tests, refer to the [CONTRIBUTING.md](CONTRIBUTING.md) file.


### Running the Tests in root-graphic-tests
To run the tests located in root-graphic-tests, execute the following commands:
```shell
cd build
ctest
```

To run it parallel on 9 cores:
```shell
cd build
ctest --parallel 9
```

To run it with additional information:
```shell
cd build
ctest --verbose
```


