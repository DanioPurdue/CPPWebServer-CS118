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
    telnet \
    cmake \
    libgtest-dev \
    libgoogle-glog-dev \
    libboost-all-dev \
    g++ `#Fb folly deps` \
    automake \
    autoconf \
    autoconf-archive \
    libtool \
    libboost-all-dev \
    libevent-dev \
    libdouble-conversion-dev \
    libgoogle-glog-dev \
    libgflags-dev \
    liblz4-dev \
    liblzma-dev \
    libsnappy-dev \
    make \
    zlib1g-dev \
    binutils-dev \
    libjemalloc-dev \
    libssl-dev \
    libiberty-dev

ENV LD_LIBRARY_PATH=/libs
ENV CPLUS_INCLUDE_PATH=/libs/include

CMD ["/bin/bash"]
