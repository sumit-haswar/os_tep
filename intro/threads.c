#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

//
// Created by Sumit Haswar on 11/26/23.
//

volatile int counter;
int loops;

void *worker(void *arg){
    int i;
    for(i = 0; i < loops; i++){
        // inc takes three instructions:
        // 1. load counter value from memory to register
        // 2. inc it
        // 3. store it back into memory
        // (they do not execute atomically, hence strange things happen)
        counter++;
    }
    return NULL;
}

int main(int argc, char *argv[]){
    loops = atoi(argv[1]);

    pthread_t p1, p2;
    printf("initial counter value: %d\n", counter);

    // create 2 threads, function running within the same memory space as other functions
    // with more than one active at a time
    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("final counter value: %d\n", counter);
    return 0;
}
