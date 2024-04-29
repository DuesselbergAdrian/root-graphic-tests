## Running root-graphics-tests

Our project includes two types of tests: one written in C++ using the ROOT framework and the other written in JavaScript using Node.js. Below are the instructions to run each test.

### 1. C++ Test with ROOT

To run the C++ test, you need to have ROOT installed on your system. ROOT is a framework for data processing, developed by CERN. If you do not have ROOT installed, please visit the [ROOT Installation Guide](https://root.cern/install/) for installation instructions.

#### Running the Test:
Open a terminal and execute the following command:
```shell
root -b -l -q /home/adrianduesselberg/root-graphic-tests test.cxx
```

### 2. Java Script Test with Node.js

To run the test, you need to have JSROOT and Node installed on your system.

#### Running the Test:
Open a terminal and execute the following command:
```shell
cd root-graphic-tests
node test.js
```

