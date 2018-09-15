#include <stdio.h>
#include <dlfcn.h>
#include "camer.c"
#include "socket.c"
#include <pthread.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void frame(void *data) {
    printf("OK\n");
}

void *print_a(void *);

int main() {

    pthread_t t0;

    if (pthread_create(&t0, NULL, get_frame, frame) == -1) {
        puts("fail to create pthread t0");
        exit(1);
    }


    //int ret = start_listen();


    void *result;
    if (pthread_join(t0, &result) == -1) {
        puts("fail to recollect t0");
        exit(1);
    }


    return 0;
}

void *print_a(void *a) {
    for (int i = 0; i < 10; i++) {
        sleep(1);
        puts("aa");
    }
    return NULL;
}