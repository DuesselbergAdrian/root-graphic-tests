# CMake generated Testfile for 
# Source directory: /home/adrianduesselberg/root-graphic-tests/test
# Build directory: /home/adrianduesselberg/root-graphic-tests/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(analyze_JSONTest "/home/adrianduesselberg/root-graphic-tests/build/test/JsonTests" "--gtest_filter=TestGraphicJSON.analyzeFunction")
set_tests_properties(analyze_JSONTest PROPERTIES  _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;22;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(archi_JSONTest "/home/adrianduesselberg/root-graphic-tests/build/test/JsonTests" "--gtest_filter=TestGraphicJSON.archiFunction")
set_tests_properties(archi_JSONTest PROPERTIES  _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;22;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(arrows_JSONTest "/home/adrianduesselberg/root-graphic-tests/build/test/JsonTests" "--gtest_filter=TestGraphicJSON.arrowsFunction")
set_tests_properties(arrows_JSONTest PROPERTIES  _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;22;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(compile_JSONTest "/home/adrianduesselberg/root-graphic-tests/build/test/JsonTests" "--gtest_filter=TestGraphicJSON.compileFunction")
set_tests_properties(compile_JSONTest PROPERTIES  _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;22;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(crown_JSONTest "/home/adrianduesselberg/root-graphic-tests/build/test/JsonTests" "--gtest_filter=TestGraphicJSON.crownFunction")
set_tests_properties(crown_JSONTest PROPERTIES  _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;22;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(analyze_SVGTest "node" "Test_SVG.js" "analyze")
set_tests_properties(analyze_SVGTest PROPERTIES  _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;29;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(archi_SVGTest "node" "Test_SVG.js" "archi")
set_tests_properties(archi_SVGTest PROPERTIES  _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;29;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(arrows_SVGTest "node" "Test_SVG.js" "arrows")
set_tests_properties(arrows_SVGTest PROPERTIES  _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;29;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(compile_SVGTest "node" "Test_SVG.js" "compile")
set_tests_properties(compile_SVGTest PROPERTIES  _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;29;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(crown_SVGTest "node" "Test_SVG.js" "crown")
set_tests_properties(crown_SVGTest PROPERTIES  _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;29;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
