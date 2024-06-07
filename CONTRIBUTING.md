## Contributing to root-graphic-test
Contributions and extensions to the root-graphic-test project are welcomed! This guide will help you add more macros to the test suite.

### Adding more macros to the test
Macros are specified in the macros_list.json file, and the corresponding macro scripts can be found in the macros folder. Below is an example structure of macros_list.json:
```json
{
    "macros": [
        {"name": "analyze", "test_type": "a", "macro_folder": "macros_1"},
        {"name": "archi", "test_type": "a", "macro_folder": "macros_1"},
        {"name": "arrows", "test_type": "a", "macro_folder": "macros_1"},
        {"name": "feynman", "test_type": "a", "macro_folder": "macros_1"},
        {"name": "first", "test_type": "a", "macro_folder": "macros_1"},
        {"name": "formula1", "test_type": "a", "macro_folder": "macros_2"},
        {"name": "framework", "test_type": "a", "macro_folder": "macros_2"},
        {"name": "gaxis", "test_type": "a", "macro_folder": "macros_2"},
        {"name": "gaxis3", "test_type": "a", "macro_folder": "macros_2"},
        {"name": "greyscale", "test_type": "a", "macro_folder": "macros_2"}
    ]

}
```
#### Steps to Add a New Macro
1. Identify the Macro: Decide the name of the macro, the type of test, and the folder where the macro script should be located.

2. Edit macros_list.json: Add a new entry to the macros_list.json file with the macro details. 
The entry should have the following format:

```json
{"name": "macro_name", "test_type": "test_type", "macro_folder": "folder_name"}
```
Replace macro_name, test_type, and folder_name with the appropriate values

3. Verify Macro Location: Ensure that the macro script is located in the specified folder within the macros directory

#### Example
If you have a new macro named new_macro of type  located in macros_3, you would add the following line to the macros_list.json file:
```json
{"name": "new_macro", "test_type": "b", "macro_folder": "macros_3"}
```

#### Full Example of macros_list.json After Adding new_macro

```json
{
    "macros": [
        {"name": "analyze", "test_type": "a", "macro_folder": "macros_1"},
        {"name": "archi", "test_type": "a", "macro_folder": "macros_1"},
        {"name": "arrows", "test_type": "a", "macro_folder": "macros_1"},
        {"name": "feynman", "test_type": "a", "macro_folder": "macros_1"},
        {"name": "first", "test_type": "a", "macro_folder": "macros_1"},
        {"name": "formula1", "test_type": "a", "macro_folder": "macros_2"},
        {"name": "framework", "test_type": "a", "macro_folder": "macros_2"},
        {"name": "gaxis", "test_type": "a", "macro_folder": "macros_2"},
        {"name": "gaxis3", "test_type": "a", "macro_folder": "macros_2"},
        {"name": "greyscale", "test_type": "a", "macro_folder": "macros_2"}
        {"name": "new_macro", "test_type": "b", "macro_folder": "macros_3"}
    ]

}
```
By following these steps, you can easily extend the test suite with new macros. We appreciate your contributions and look forward to seeing your additions!

### Submitting Your Changes (NOT DONE)
1. **Fork the Repository**: Create a fork of the root-graphic-test repository on GitHub.

2. **Create a Branch**: Make a new branch for your changes.
    ```sh
    git checkout -b add-new-macro
    ```

3. **Commit Your Changes**: Add and commit your changes.
    ```sh
    git add macros_list.json
    git commit -m "Add new macro 'new_macro' to the test suite"
    ```

4. **Push to Your Branch**: Push your changes to your fork.
    ```sh
    git push origin add-new-macro
    ```

5. **Open a Pull Request**: Open a pull request on GitHub from your branch to the main repository.

Thank you for contributing to the root-graphic-test project!