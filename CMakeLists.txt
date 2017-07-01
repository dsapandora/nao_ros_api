cmake_minimum_required(VERSION 2.8)
project(brownie)

find_package(qibuild)

# Create a executable named brownie
# with the source file: main.cpp
qi_create_bin(brownie "main.cpp"  DEPENDS QI)
qi_use_lib(brownie ALCOMMON ALPROXIES)

# Add a simple test:
qi_create_test(test_brownie "test.cpp")
