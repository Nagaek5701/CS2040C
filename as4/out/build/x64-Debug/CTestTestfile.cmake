# CMake generated Testfile for 
# Source directory: C:/Users/Keagan/Desktop/nussy4/CS2040c/as4
# Build directory: C:/Users/Keagan/Desktop/nussy4/CS2040c/as4/out/build/x64-Debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(HeapTest "C:/Users/Keagan/Desktop/nussy4/CS2040c/as4/out/build/x64-Debug/heap_test.exe")
set_tests_properties(HeapTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Keagan/Desktop/nussy4/CS2040c/as4/CMakeLists.txt;26;add_test;C:/Users/Keagan/Desktop/nussy4/CS2040c/as4/CMakeLists.txt;0;")
add_test(QueueSimTest "C:/Users/Keagan/Desktop/nussy4/CS2040c/as4/out/build/x64-Debug/queue_sim_test.exe")
set_tests_properties(QueueSimTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Keagan/Desktop/nussy4/CS2040c/as4/CMakeLists.txt;31;add_test;C:/Users/Keagan/Desktop/nussy4/CS2040c/as4/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
