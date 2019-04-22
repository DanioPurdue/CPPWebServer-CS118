#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <memory.h>
#include "../include/header.h"
#include "../include/request.h"
#include "../include/RequestParser.h"
#include "../include/ResponsePrep.h"

#define MYPORT 5000 //server supposes to bind the socket to this port
#define BACKLOG 10  //number of connections allowed

using namespace std;
int main(int argc, char *argv[])
{
    cout << "Server is running at port: " << MYPORT << endl;
    int sockfd, new_fd;
    struct sockaddr_in my_addr;    /* my address */
    struct sockaddr_in their_addr; /* connector addresss */
    socklen_t sin_size;
    size_t read_buff_size = 512;
    char *read_buff = new char[read_buff_size]; //[read_buff_size];

    /*create a socket*/
    if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Failed to create socket");
        exit(1);
    }
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(MYPORT);
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(my_addr.sin_zero, '\0', sizeof(my_addr.sin_zero));

    /* bind the socket to the specified port*/
    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1)
    {
        perror("Failed to bind the socket to a specific port");
        exit(1);
    }

    if (listen(sockfd, BACKLOG) == -1)
    {
        perror("Failed to listen on socket");
        exit(1);
    }

    RequestParser rp;
    ResponsePrep res_prep;
    while (1)
    {
        sin_size = sizeof(struct sockaddr_in);
        if ((new_fd = accept(sockfd, (sockaddr *)&their_addr, &sin_size)) == -1)
        {
            perror("Failed to accept");
        }

        // cout << "A client connected from" << inet_ntoa(their_addr.sin_addr) << endl; //TODO: Remove for final submission
        if (read(new_fd, (void *)read_buff, read_buff_size) == -1)
        {
            perror("Couldn't read from client socket");
        }
        else
        {
            // cout << "Read from socket: \n";
            cout << "\n==================Client Request===================" << endl;
            for (size_t i = 0; i < read_buff_size; ++i)
            {
                cout << read_buff[i];
            }
            unique_ptr<request> req;
            if ((req = rp.parseRequest(read_buff, read_buff_size)) != nullptr)
            {
                const string uri = req->uri;
                int resp_size;
                char * response = res_prep.getResponse(uri, &resp_size);
                send(new_fd, (const void *)response, resp_size, 0);
                if (response != nullptr) {
                    delete [] response;
                    response = nullptr;
                }
            }
        }
        close(new_fd);
    }
    close(sockfd);
    return 0;
}