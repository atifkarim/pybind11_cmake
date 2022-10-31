rm -rf build/ bin/ lib/
rm example/py/*.so
mkdir build && cd build
cmake .. -DPYTHON_EXECUTABLE=/usr/bin/python3.8 && make
cd ../bin/
./pybind_cpp_exec

cd ..
pwd
cp lib/*.so example/py/
