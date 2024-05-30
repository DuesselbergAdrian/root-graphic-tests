## Contributing to root-graphic-test
Contributions and extensions are welcomed.

### Adding more macros to the test
The macros are specified in the macros_list.json. The coresponding macros can be found in the macros folder. the macros_list.json looks somewhat like this.
```shell
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

To include tests for an additional macro, one has to add an extra line in this file and specfy the name, the type of test one want to test and the folder, where it is located inside the macros folder.



