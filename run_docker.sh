#!/bin/bash

cd ~

# Cloning required repository
git clone https://github.com/atifkarim/pybind11_cmake.git
git clone https://github.com/pybind/pybind11.git forked_repo/pybind11
ls

# Building project
cd pybind11_cmake
rm -rf build/ bin/ lib/
mkdir build && cd build
cmake .. -DPYTHON_EXECUTABLE=$(which python) && make

# Execute cpp binary
cd ../bin/
./pybind_cpp_exec

# Copying library file to python file's directory
cd ..
cp lib/*.so example/py/

# Execute python script
cd example/py/
python3 main.py
