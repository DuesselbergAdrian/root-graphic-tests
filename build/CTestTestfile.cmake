# CMake generated Testfile for 
# Source directory: /home/adrianduesselberg/root-graphic-tests
# Build directory: /home/adrianduesselberg/root-graphic-tests/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(analyze_RootTest_o "root" "-l" "-b" "-q" "--web=off" "Test_Root.cpp(\"analyze\", \"o\", \"macros_1\")")
set_tests_properties(analyze_RootTest_o PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;53;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(archi_RootTest_o "root" "-l" "-b" "-q" "--web=off" "Test_Root.cpp(\"archi\", \"o\", \"macros_1\")")
set_tests_properties(archi_RootTest_o PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;53;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(arrows_RootTest_o "root" "-l" "-b" "-q" "--web=off" "Test_Root.cpp(\"arrows\", \"o\", \"macros_1\")")
set_tests_properties(arrows_RootTest_o PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;53;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(compile_RootTest_j "root" "-l" "-b" "-q" "Test_Root.cpp(\"compile\", \"j\", \"macros_1\")")
set_tests_properties(compile_RootTest_j PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;47;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(crown_RootTest_j "root" "-l" "-b" "-q" "Test_Root.cpp(\"crown\", \"j\", \"macros_1\")")
set_tests_properties(crown_RootTest_j PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;47;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(basic3d_RootTest_j "root" "-l" "-b" "-q" "Test_Root.cpp(\"basic3d\", \"j\", \"macros_1\")")
set_tests_properties(basic3d_RootTest_j PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;47;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(ellipse_RootTest_j "root" "-l" "-b" "-q" "Test_Root.cpp(\"ellipse\", \"j\", \"macros_1\")")
set_tests_properties(ellipse_RootTest_j PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;47;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(eval_JsRootTest_s "node" "Test_JsRoot.js" "eval")
set_tests_properties(eval_JsRootTest_s PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;59;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(event_JsRootTest_s "node" "Test_JsRoot.js" "event")
set_tests_properties(event_JsRootTest_s PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;59;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(feynman_JsRootTest_s "node" "Test_JsRoot.js" "feynman")
set_tests_properties(feynman_JsRootTest_s PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;59;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
add_test(first_JsRootTest_s "node" "Test_JsRoot.js" "first")
set_tests_properties(first_JsRootTest_s PROPERTIES  WORKING_DIRECTORY "/home/adrianduesselberg/root-graphic-tests" _BACKTRACE_TRIPLES "/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;59;add_test;/home/adrianduesselberg/root-graphic-tests/CMakeLists.txt;0;")
