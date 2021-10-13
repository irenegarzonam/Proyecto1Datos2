#ifndef SERVIDOR_SOCKETSERVER_H
#define SERVIDOR_SOCKETSERVER_H
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <cstring>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>

using namespace std;
struct dataSocket{
    int descriptor;
    sockaddr_in info;
};

class SocketServer {
public:
    SocketServer();
    void run();
    void send_message(const char* msn);
private:
    static void ctrlC(string msg);
    int descriptor{};
    sockaddr_in info{};
    vector<int> clients;
    bool create_socket();
    bool link_kernel();
    static void* client_controller(void* obj);
};


#endif //SERVIDOR_SOCKETSERVER_H
