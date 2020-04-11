#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uv.h>


int main() {
    loop = uv_default_loop();
    uv_tcp_t* socket = (uv_tcp_t*)malloc(sizeof(uv_tcp_t));
    uv_tcp_init(loop, socket);

    uv_connect_t* connect = (uv_connect_t*)malloc(sizeof(uv_connect_t));

    struct sockaddr_in dest;
    uv_ip4_addr("127.0.0.1", 80, &dest);

    uv_tcp_connect(connect, socket, dest, on_connect);
    return 0;
}