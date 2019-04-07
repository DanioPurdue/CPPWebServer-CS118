### Base environment container ###
# Get the base Ubuntu image from Docker Hub
FROM ubuntu:16.04 as base

# Update the base image and install build environment
RUN apt-get update && apt-get install -y \
    build-essential \
    curl \
    netcat \
    net-tools \
    iproute2 \
    vim \
    git \
    telnet
    #     cmake \
    #     libboost-log-dev \
    #     libboost-signals-dev \
    #     libboost-system-dev \
    #     libgtest-devsr
