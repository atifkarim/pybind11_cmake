# syntax=docker/dockerfile:1
FROM python:3.10

# Script file where necessary commands are written to build and run the project
COPY prepare_project.sh /

# Installing CMake build tool
RUN wget -qO- "https://cmake.org/files/v3.17/cmake-3.17.0-Linux-x86_64.tar.gz" | tar --strip-components=1 -xz -C /usr/local

# Copy supervisor configuration file
COPY supervisord.conf /etc/supervisor/conf.d/supervisord.conf

# Executing script file
CMD ["supervisord", "-n"]
