#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <sys/wait.h> 
#include <netinet/in.h>
#include <iostream>
#define MYPORT 5000 //server supposes to bind the socket to this port
#define BACKLOG 10

using namespace std;
int main(int argc, char * argv []) {
    cout << "Hello Server !" << endl;
    return 0;
}