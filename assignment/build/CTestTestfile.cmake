# CMake generated Testfile for 
# Source directory: /home/alex/Documents/ivs_project_1_2021/assignment
# Build directory: /home/alex/Documents/ivs_project_1_2021/assignment/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(WhiteBoxTest.MatrixCreate "/home/alex/Documents/ivs_project_1_2021/assignment/build/white_box_test" "--gtest_filter=WhiteBoxTest.MatrixCreate")
set_tests_properties(WhiteBoxTest.MatrixCreate PROPERTIES  _BACKTRACE_TRIPLES "/home/alex/Documents/ivs_project_1_2021/assignment/GoogleTest.cmake;39;add_test;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;36;GTEST_ADD_TESTS;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;0;")
add_test(NonEmptyQueue.Insert "/home/alex/Documents/ivs_project_1_2021/assignment/build/tdd_test" "--gtest_filter=NonEmptyQueue.Insert")
set_tests_properties(NonEmptyQueue.Insert PROPERTIES  _BACKTRACE_TRIPLES "/home/alex/Documents/ivs_project_1_2021/assignment/GoogleTest.cmake;39;add_test;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;0;")
add_test(NonEmptyQueue.RemoveAllBackward "/home/alex/Documents/ivs_project_1_2021/assignment/build/tdd_test" "--gtest_filter=NonEmptyQueue.RemoveAllBackward")
set_tests_properties(NonEmptyQueue.RemoveAllBackward PROPERTIES  _BACKTRACE_TRIPLES "/home/alex/Documents/ivs_project_1_2021/assignment/GoogleTest.cmake;39;add_test;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;0;")
add_test(NonEmptyQueue.RemoveAllForward "/home/alex/Documents/ivs_project_1_2021/assignment/build/tdd_test" "--gtest_filter=NonEmptyQueue.RemoveAllForward")
set_tests_properties(NonEmptyQueue.RemoveAllForward PROPERTIES  _BACKTRACE_TRIPLES "/home/alex/Documents/ivs_project_1_2021/assignment/GoogleTest.cmake;39;add_test;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;0;")
add_test(NonEmptyQueue.Find "/home/alex/Documents/ivs_project_1_2021/assignment/build/tdd_test" "--gtest_filter=NonEmptyQueue.Find")
set_tests_properties(NonEmptyQueue.Find PROPERTIES  _BACKTRACE_TRIPLES "/home/alex/Documents/ivs_project_1_2021/assignment/GoogleTest.cmake;39;add_test;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;0;")
add_test(NonEmptyQueue.Length "/home/alex/Documents/ivs_project_1_2021/assignment/build/tdd_test" "--gtest_filter=NonEmptyQueue.Length")
set_tests_properties(NonEmptyQueue.Length PROPERTIES  _BACKTRACE_TRIPLES "/home/alex/Documents/ivs_project_1_2021/assignment/GoogleTest.cmake;39;add_test;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;0;")
add_test(EmptyQueue.Insert "/home/alex/Documents/ivs_project_1_2021/assignment/build/tdd_test" "--gtest_filter=EmptyQueue.Insert")
set_tests_properties(EmptyQueue.Insert PROPERTIES  _BACKTRACE_TRIPLES "/home/alex/Documents/ivs_project_1_2021/assignment/GoogleTest.cmake;39;add_test;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;0;")
add_test(EmptyQueue.Remove "/home/alex/Documents/ivs_project_1_2021/assignment/build/tdd_test" "--gtest_filter=EmptyQueue.Remove")
set_tests_properties(EmptyQueue.Remove PROPERTIES  _BACKTRACE_TRIPLES "/home/alex/Documents/ivs_project_1_2021/assignment/GoogleTest.cmake;39;add_test;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;0;")
add_test(EmptyQueue.Find "/home/alex/Documents/ivs_project_1_2021/assignment/build/tdd_test" "--gtest_filter=EmptyQueue.Find")
set_tests_properties(EmptyQueue.Find PROPERTIES  _BACKTRACE_TRIPLES "/home/alex/Documents/ivs_project_1_2021/assignment/GoogleTest.cmake;39;add_test;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;0;")
add_test(EmptyQueue.Length "/home/alex/Documents/ivs_project_1_2021/assignment/build/tdd_test" "--gtest_filter=EmptyQueue.Length")
set_tests_properties(EmptyQueue.Length PROPERTIES  _BACKTRACE_TRIPLES "/home/alex/Documents/ivs_project_1_2021/assignment/GoogleTest.cmake;39;add_test;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;/home/alex/Documents/ivs_project_1_2021/assignment/CMakeLists.txt;0;")
subdirs("googletest-build")
