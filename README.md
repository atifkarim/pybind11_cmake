Pybind11 & CMake
================

[![CI](https://github.com/atifkarim/pybind11_cmake/actions/workflows/ci.yml/badge.svg?branch=main)](https://github.com/atifkarim/pybind11_cmake/actions/workflows/ci.yml)
[![Documentation Status](https://readthedocs.org/projects/pybind11-cmake/badge/?version=latest)](https://pybind11-cmake.readthedocs.io/en/latest/?badge=latest)


The goal of this repository to work with pybind11 and CMake. Here, my plan is to introduce advanced C++ binding.

# Cloning Repositories

- This project is dependent on [`pybind11`](https://github.com/pybind/pybind11/tree/master) which is used in this project as a helper repository.
- To clone and use pybind11 follow the following approach.
    - Go to the directory where [`pybind11_cmake`](https://github.com/atifkarim/pybind11_cmake) project will be cloned and clone it with the following command
    ```sh
    git clone https://github.com/atifkarim/pybind11_cmake.git
    ```

    - Now keep  [`pybind11`](https://github.com/pybind/pybind11/tree/master) in the same level of the current project. I have kept it in a common repository named `forked repo`
    ```sh
    mkdir forked_repo && cd forked_repo
    git clone https://github.com/pybind/pybind11.git
    ```
    - Finally the directory structure will be as like as follows
    ```sh
    forked_repo/
    └── pybind11
    pybind11_cmake/
    ```

# Building project

To build the project necessary commands are written in `run_project.sh` file which is located in the `root` of the project. Execute it from the terminal by writing `./run_project.sh`.

# Documentation

This [RTD Site](https://pybind11-cmake.readthedocs.io/en/latest/) is used to host the documentation of the project

# Planning

[Here](ToDo.md) my planning is written regarding the project

# Building project issue

1. Sometimes CMAKE faces issue while building project regarding finding appropriate python package. See [this](https://github.com/pybind/pybind11/issues/2154). Possible solution:

    ```sh
    cmake .. -DPYTHON_EXECUTABLE=/usr/bin/python3.8
    ```
    or,
    ```sh
    cmake .. -DPYTHON_EXECUTABLE=$(which python)
    ```
