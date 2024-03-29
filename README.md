C++ Datatypes <--> Pybind11
===========================

[![CI](https://github.com/atifkarim/pybind11_cmake/actions/workflows/ci.yml/badge.svg?branch=main)](https://github.com/atifkarim/pybind11_cmake/actions/workflows/ci.yml)
[![Documentation Status](https://readthedocs.org/projects/pybind11-cmake/badge/?version=latest)](https://pybind11-cmake.readthedocs.io/en/latest/?badge=latest)


THe goal if this project is to interface C++ type with Python. Pybind11 is used for this interfacing feature. CMaek is used as build tool.

# Required Repositories

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
- To clone and prepare the repository by following current structure one can use [this script](https://github.com/atifkarim/pybind11_cmake/blob/main/prepare_project.sh)

# Required python package

- Necessary python files are located in `example/py` dorectory
- Used `pipreqs` module to create `requirements.txt` file to install necessary python module
  > Remember, python module generated by pybind11 will not be counted here
- To use `pipreqs`
  - `pip install pipreqs` -> [Source](https://github.com/bndr/pipreqs)
  - Usage to create requirements.txt file: `pipreqs example/py/`

# Building project

To build the project necessary commands are written in `run_project.sh` file which is located in the `root` of the project. Execute it from the terminal by writing `./run_project.sh`.

# Documentation

This [RTD Site](https://pybind11-cmake.readthedocs.io/en/latest/) is used to host the documentation of the project

# Containerization

This project is available in Docker. See [this](https://hub.docker.com/r/atifkarim/test_image_pybind11_cmake) to use the docker image.

## Command to run docker image

- After preparing docker environment in your system, pull the docker image
  ```sh
  docker pull atifkarim/test_image_pybind11_cmake
  ```
- After pulling check images list by `docker images` command
- Now, run it using the following command
      
  - Without interactive terminal
    ```sh
    docker run atifkarim/test_image_pybind11_cmake
    ```
  - Without interactive terminal
    ```sh
    docker run -it atifkarim/test_image_pybind11_cmake bash
    ```
      - Now, here you can see the file `prepare_project.sh`.
      - Make it executable by running `chmod +x prepare_project.sh`
      - Now run that file by using `./prepare_project.sh`.
      - This command will clone required repo and execute cpp, py file. Later, developer can do further development here.
      - I have found the required repo by going to home directory `cd ~`


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
