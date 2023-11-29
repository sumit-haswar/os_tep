//
// Created by Sumit Haswar on 11/26/23.
//

#ifndef OS_TEP_COMMON_H
#define OS_TEP_COMMON_H

#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>

double GetTime() {
    struct timeval t;
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    return (double) t.tv_sec + (double) t.tv_usec/1e6;
}

void Spin(int duration){
    double t = GetTime();
    while((GetTime() - t) < (double) duration){

    }
}
#endif //OS_TEP_COMMON_H
