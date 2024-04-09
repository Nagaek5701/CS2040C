# CMake generated Testfile for 
# Source directory: C:/Users/Keagan/Desktop/nussy4/CS2040c/as2
# Build directory: C:/Users/Keagan/Desktop/nussy4/CS2040c/as2/out/build/x64-Debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(LinkedListTest "C:/Users/Keagan/Desktop/nussy4/CS2040c/as2/out/build/x64-Debug/linked_list_test.exe")
set_tests_properties(LinkedListTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Keagan/Desktop/nussy4/CS2040c/as2/CMakeLists.txt;24;add_test;C:/Users/Keagan/Desktop/nussy4/CS2040c/as2/CMakeLists.txt;0;")
add_test(FoodTest "C:/Users/Keagan/Desktop/nussy4/CS2040c/as2/out/build/x64-Debug/food_test.exe")
set_tests_properties(FoodTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Keagan/Desktop/nussy4/CS2040c/as2/CMakeLists.txt;29;add_test;C:/Users/Keagan/Desktop/nussy4/CS2040c/as2/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
