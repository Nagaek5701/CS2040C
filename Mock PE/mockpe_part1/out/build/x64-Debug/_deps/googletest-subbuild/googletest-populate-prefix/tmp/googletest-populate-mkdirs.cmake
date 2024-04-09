# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Keagan/Desktop/nussy4/CS2040c/Mock PE/mockpe_part1/out/build/x64-Debug/../../../googletest-03597a01ee50ed33e9dfd640b249b4be3799d395"
  "C:/Users/Keagan/Desktop/nussy4/CS2040c/Mock PE/mockpe_part1/out/build/x64-Debug/_deps/googletest-build"
  "C:/Users/Keagan/Desktop/nussy4/CS2040c/Mock PE/mockpe_part1/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "C:/Users/Keagan/Desktop/nussy4/CS2040c/Mock PE/mockpe_part1/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "C:/Users/Keagan/Desktop/nussy4/CS2040c/Mock PE/mockpe_part1/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "C:/Users/Keagan/Desktop/nussy4/CS2040c/Mock PE/mockpe_part1/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "C:/Users/Keagan/Desktop/nussy4/CS2040c/Mock PE/mockpe_part1/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Keagan/Desktop/nussy4/CS2040c/Mock PE/mockpe_part1/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/Keagan/Desktop/nussy4/CS2040c/Mock PE/mockpe_part1/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
