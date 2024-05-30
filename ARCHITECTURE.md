# Project Architecture

## Overview

This document provides an overview of the project's architecture, including the main components and their interactions.

## Directory Structure

The project is organized as follows:

```plaintext
root-graphic-test/
├── macros/
│ ├── macros_1/
│ ├── macros_2/
│ └── macros_3/
├── tests/
│ ├── unit/
│ └── integration/
├── src/
│ ├── main/
│ └── utils/
├── docs/
│ └── images/
├── scripts/
│ └── setup.sh
├── README.md
├── CONTRIBUTING.md
├── ARCHITECTURE.md
└── LICENSE.md
```
### Directories

- **macros/**: Contains all macro scripts organized in subfolders.
- **tests/**: Contains unit and integration tests.
  - **unit/**: Unit tests for individual components.
  - **integration/**: Integration tests for the whole system.
- **src/**: Source code of the project.
  - **main/**: Main application code.
  - **utils/**: Utility functions and helpers.
- **docs/**: Documentation files.
  - **images/**: Images used in documentation.
- **scripts/**: Shell scripts for setup and maintenance.

### Main Components

1. **Macros**: The core functionality of the project, divided into different types and stored in separate folders.
2. **Tests**: Ensures the quality and correctness of the code.
3. **Source Code**: The primary codebase of the application.

### Interaction Between Components

- The **macros** are executed by the main application found in the **src/main/** directory.
- The **utils** directory provides helper functions used across the main application and tests.
- **Unit tests** validate individual pieces of code, while **integration tests** ensure that different parts of the application work together correctly.

## Getting Started

For more details on how to get started with the project, refer to the [README.md](README.md) file.

## Contributing

Please see the [CONTRIBUTING.md](CONTRIBUTING.md) file for guidelines on how to contribute to this project.