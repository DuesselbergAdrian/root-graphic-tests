# CMake generated Testfile for 
# Source directory: /home/adrianduesselberg/root-graphic-tests/test
# Build directory: /home/adrianduesselberg/root-graphic-tests/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(analyze_JSONTest "/home/adrianduesselberg/root-graphic-tests/build/test/JsonTests" "--gtest_filter=TestJSON.analyzeFunction")
set_tests_properties(analyze_JSONTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;28;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(archi_JSONTest "/home/adrianduesselberg/root-graphic-tests/build/test/JsonTests" "--gtest_filter=TestJSON.archiFunction")
set_tests_properties(archi_JSONTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;28;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(arrows_JSONTest "/home/adrianduesselberg/root-graphic-tests/build/test/JsonTests" "--gtest_filter=TestJSON.arrowsFunction")
set_tests_properties(arrows_JSONTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;28;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(compile_JSONTest "/home/adrianduesselberg/root-graphic-tests/build/test/JsonTests" "--gtest_filter=TestJSON.compileFunction")
set_tests_properties(compile_JSONTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;28;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(crown_JSONTest "/home/adrianduesselberg/root-graphic-tests/build/test/JsonTests" "--gtest_filter=TestJSON.crownFunction")
set_tests_properties(crown_JSONTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;28;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(basic3d_JSONTest "/home/adrianduesselberg/root-graphic-tests/build/test/JsonTests" "--gtest_filter=TestJSON.basic3dFunction")
set_tests_properties(basic3d_JSONTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;28;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(analyze_SVGTest "node" "Test_SVG.js" "analyze")
set_tests_properties(analyze_SVGTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;37;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(archi_SVGTest "node" "Test_SVG.js" "archi")
set_tests_properties(archi_SVGTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;37;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(arrows_SVGTest "node" "Test_SVG.js" "arrows")
set_tests_properties(arrows_SVGTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;37;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(compile_SVGTest "node" "Test_SVG.js" "compile")
set_tests_properties(compile_SVGTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;37;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(crown_SVGTest "node" "Test_SVG.js" "crown")
set_tests_properties(crown_SVGTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;37;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
add_test(basic3d_SVGTest "node" "Test_SVG.js" "basic3d")
set_tests_properties(basic3d_SVGTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;37;add_test;/home/adrianduesselberg/root-graphic-tests/test/CMakeLists.txt;0;")
