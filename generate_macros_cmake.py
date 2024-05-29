import json

# Read the JSON file
with open('macros_list.json', 'r') as f:
    data = json.load(f)

# Extract the list of macros
macros = data.get("macros", [])

# Generate the CMake list
cmake_content = "set(macros\n"
for macro in macros:
    name = macro["name"]
    test_type = macro["test_type"]
    macro_folder = macro["macro_folder"]
    cmake_content += f"    \"{name} {test_type} {macro_folder}\"\n"
cmake_content += ")\n"

# Write the CMake list to a file
with open('macros.cmake', 'w') as f:
    f.write(cmake_content)