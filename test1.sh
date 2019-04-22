#!/bin/bash

# Test >100 Mb random file
RAND_FILE="rand"

dd if=/dev/urandom of=$RAND_FILE bs=64M count=4 # Command to make random >100Mb binary file
./server > /dev/null 2>&1 &
SERVER_PID=$!

printf '%s\r\n%s\r\n%s\r\n\r\n'             \
    "GET / HTTP/1.1"                        \
    "Host: www.example.com"                 \
    "Connection: close"                     \
    | nc 127.0.0.1 5000


echo "Shut down server with PID="$SERVER_PID
kill -s SIGINT $SERVER_PID
