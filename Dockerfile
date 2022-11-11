# syntax=docker/dockerfile:1
FROM python:3.8
RUN mkdir pybind11_cmake
ADD . pybind11_cmake/
RUN git clone https://github.com/pybind/pybind11.git forked_repo/pybind11 \
  && wget -qO- "https://cmake.org/files/v3.17/cmake-3.17.0-Linux-x86_64.tar.gz" | tar --strip-components=1 -xz -C /usr/local \
  && cd pybind11_cmake \
  && mkdir build \
  && cd build \
  && cmake .. -DPYTHON_EXECUTABLE=$(which python) \
  && make \
  && cd ../bin \
  && ./pybind_cpp_exec
#   && cd pybind11_cmake \
#   && chmod +x run_project.sh \
#   && ./run_project.sh

# CMD [ "bash", "./pybind11_cmake/run_docker.sh" ]
