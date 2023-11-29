#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "common.h"

//
// Created by Sumit Haswar on 11/26/23.
//
int main(int argc, char *argcv[]) {
    int *p = malloc(sizeof(int));

    printf("(%d) address pointed out by p: %p \n", getpid(), p);

    *p = 0;
    while (1) {
        Spin(2);
        *p = *p + 1;
        printf("(%d) Value of p: %d \n", getpid(), *p);
    }

    return 0;
}
