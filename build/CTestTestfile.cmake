# CMake generated Testfile for 
# Source directory: /home/adrianduesselberg/root-graphic-tests
# Build directory: /home/adrianduesselberg/root-graphic-tests/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(analyze_RootTest "root" "-l" "-b" "-q" "Test_Root.cpp(\"analyze\", \"j\" )")
set_tests_properties(analyze_RootTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;46;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(archi_RootTest "root" "-l" "-b" "-q" "--web=off" "Test_Root.cpp(\"archi\", \"o\" )")
set_tests_properties(archi_RootTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;52;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(arrows_RootTest "root" "-l" "-b" "-q" "--web=off" "Test_Root.cpp(\"arrows\", \"o\" )")
set_tests_properties(arrows_RootTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;52;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(compile_RootTest "root" "-l" "-b" "-q" "Test_Root.cpp(\"compile\", \"j\" )")
set_tests_properties(compile_RootTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;46;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(crown_RootTest "root" "-l" "-b" "-q" "--web=off" "Test_Root.cpp(\"crown\", \"o\" )")
set_tests_properties(crown_RootTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;52;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(basic3d_RootTest "root" "-l" "-b" "-q" "--web=off" "Test_Root.cpp(\"basic3d\", \"o\" )")
set_tests_properties(basic3d_RootTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;52;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(ellipse_RootTest "root" "-l" "-b" "-q" "--web=off" "Test_Root.cpp(\"ellipse\", \"o\" )")
set_tests_properties(ellipse_RootTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;52;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(analyze_JsRootTest "node" "Test_JsRoot.js" "analyze")
set_tests_properties(analyze_JsRootTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;65;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(archi_JsRootTest "node" "Test_JsRoot.js" "archi")
set_tests_properties(archi_JsRootTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;65;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(arrows_JsRootTest "node" "Test_JsRoot.js" "arrows")
set_tests_properties(arrows_JsRootTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;65;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(compile_JsRootTest "node" "Test_JsRoot.js" "compile")
set_tests_properties(compile_JsRootTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;65;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(crown_JsRootTest "node" "Test_JsRoot.js" "crown")
set_tests_properties(crown_JsRootTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;65;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(basic3d_JsRootTest "node" "Test_JsRoot.js" "basic3d")
set_tests_properties(basic3d_JsRootTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;65;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(ellipse_JsRootTest "node" "Test_JsRoot.js" "ellipse")
set_tests_properties(ellipse_JsRootTest PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;65;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
