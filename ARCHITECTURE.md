# Project Architecture

## Overview

This document provides an overview of the project's architecture, including the main components and their interactions.

## Directory Structure

The project is organized as follows:

```plaintext
root-graphic-test/
├── macros/
│ ├── graphics/
│ ├── graphs/
│ ├── hist/
│ └── ....
├── json_ref/
├── svg_ref/
├── old_svg_pro/
├── old_svg_ref/
│
├── package.json
│
├── node_modules/
│ ├── chalk/
│ ├── xml-formatter/
│ └── xml-parser-xo/
│
├── CMAKELists.txt
├── macros_list.json
├── generate_macros_cmake.py
│
├── Test_Root.cpp
├── Test_Root.hpp
├── Test_JsRoot.js
│
├── README.md
├── CONTRIBUTING.md
├── ARCHITECTURE.md
└── LICENSE.md
```
### Directories

- **macros/**: Contains all macro scripts organized in subfolders.
  - **macros_1/, macros_2/,graphs,...**: Subfolders with specific macros scripts.
- **json_ref/**: Contains reference JSON files for tests and comparisons.
- **svg_ref/**: Contains reference SVG files for tests and comparisons.
- **old_svg_pro/**: Contains produced/generated old SVG files.
- **old_svg_ref/**: Contains reference old SVG files for tests and comparisons.
- **node_modules/**: Conatins Node.js modules required for the project
  - **chalk/, xml-formatter/, xml-pasrer-xo/**: Specific Node.js modules used by the project.

### Main Components

1. **ROOT Macros**: Used to create different graphics with ROOT/JSROOT, divided into different types and stored in separate folders.
2. **Build and Configuration Files**:
  - **CMakeLists.txt**: Configuration file for CMake build automation.
  - **macros_list.json**: Lists the macros used in the project.
  - **generate_macros_cmake.py**: Python script to generate CMake configurations for macros.
3. **Source Code**:  Primary codebase of the project.
  - **Test_Root.cpp**: Main C++ test source file.
  - **Test_Root.hpp**: Header file for the C++ test.
  - **Test_JsRoot.js**: JavaScript file for testing JSROOT.

### Interaction Between Components

- The **macros** are executed as part of the test suite and are defined in the **macros/** directory.
- **JSON and SVG files** are used for reference and production configurations in testing scenarios.
- **Build and configuration files** manage the build process and macro generation.
- **Source code files** implement the core testing logic in C++ and JavaScript.

## Getting Started

For more details on how to get started with the project, refer to the [README.md](README.md) file.

## Contributing

Please see the [CONTRIBUTING.md](CONTRIBUTING.md) file for guidelines on how to contribute to this project.