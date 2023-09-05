rm -rf build/ bin/ lib/
rm example/py/*.so
mkdir build && cd build
cmake .. -DPYTHON_EXECUTABLE=$(which python) && make
cd ../bin/
./pybind_cpp_exec

cd ..
cp lib/*.so example/py/

cd example/py/
$(which python) main.py
