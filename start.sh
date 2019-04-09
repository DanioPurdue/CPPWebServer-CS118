#!/bin/bash

DOCKER_SOCK=/var/run/docker.sock
DOCKER_NAME="devel_env_118"

# TODO: See first answer here:
# https://stackoverflow.com/questions/39525820/docker-port-forwarding-not-working

function build_image(){
    # Build image
    docker build \
    -f "docker/base.Dockerfile" \
    -t $1 .
}

function get_absolute_path() {
    # Make SRC_DIR into an absolute path if it is not already
    if [[ ! -z $1 ]]
    then
        # If the specified repo dir is absolute, use it
        if [[ $1 == /* ]]
        then
            echo $1
        else
            # Otherwise, append it to the existing absolute dir
            echo "$(pwd)/$1"
        fi
    else
        pwd
    fi
}

function is_container_existing() {
    docker container inspect $1 > /dev/null 2>&1
}

function stop_container() {
    docker container stop $1
}

function remove_container() {
    docker container rm $1
}

function create_container() {
    SRC_DIR=$(get_absolute_path $SRC_DIR_ARG)
    echo "Using source directory '$SRC_DIR', mapping to '.'"
    
    if is_container_existing $1
    then
        echo "Stopping stale container"
        stop_container $1
    fi
    if is_container_existing $1
    then
        echo "Removing stale container"
        remove_container $1
    fi
    
    # Run image
    if [ -z "$PORT" ]
    then
        docker run -it --rm \
        -v "${SRC_DIR}":"${SRC_DIR}" \
        --security-opt seccomp=unconfined --cap-add SYS_PTRACE \
        --name $1 \
        --hostname $1 \
        -w ${SRC_DIR} \
        $1
    else
        docker run -it --rm \
        -v "${SRC_DIR}":"${SRC_DIR}" \
        --security-opt seccomp=unconfined --cap-add SYS_PTRACE \
        --name $1 \
        --hostname $1 \
        -p 127.0.0.1:${PORT}:${PORT} \
        -w ${SRC_DIR} \
        $1
    fi
}

function exec_shell() {
    docker exec -w ${SRC_DIR} -it $1 /bin/bash
}

# Source: https://stackoverflow.com/questions/192249/how-do-i-parse-command-line-arguments-in-bash
FLAGS=() #Flags
while [[ $# -gt 0 ]]
do
    key="$1"
    
    
    case $key in
        -p|--port)
            PORT="$2"
            shift # past argument
            shift # past value
        ;;
        -m|--mount)
            MOUNT="$2"
            shift # past argument
            shift # past value
        ;;
        *)    # unknown option
            FLAGS+=("$1") # save it in an array for later
            shift # past argument
        ;;
    esac
done

build_image $DOCKER_NAME

set -- "${FLAGS[@]}" # restore FLAGS parameters
echo Docker exposed with port mapping "${PORT}"
echo Docker mounted at "${MOUNT}"
echo From source dir "${SRC_DIR}"


create_container $DOCKER_NAME