#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>
//#include <iostream>


int currentIndex = 1;
int arrayLength;

void *numeric(char* myStr[]) {
    int internalIndex;
    while (currentIndex < arrayLength) {
        internalIndex = currentIndex;
        //myStr[internalIndex] > 47 && myStr[internalIndex] < 58
        if(isdigit(myStr[internalIndex][0])) {
            printf("numeric: %s\n", myStr[internalIndex]);
            //std::cout << "numeric: " << myStr[internalIndex] << std::endl;
            currentIndex++;
        }
        while (internalIndex == currentIndex) {
            continue;
        }
    }
}

void *alpha(char* myStr[]) {
    int internalIndex;
    while (currentIndex < arrayLength) {
        internalIndex = currentIndex;
        if(isalpha(myStr[internalIndex][0])) {
            printf("alpha: %s\n", myStr[internalIndex]);
            currentIndex++;
        }
        while (internalIndex == currentIndex) {
            continue;
        }
    }
}

int main(int argc, char* argv[]) {
    arrayLength = argc;
    pthread_t alpha_thread, num_threadl;
    pthread_create(&alpha_thread, NULL, reinterpret_cast<void* (*)(void*)>(alpha), argv);
    pthread_create(&num_threadl, NULL, reinterpret_cast<void* (*)(void*)>(numeric), argv);
    pthread_join(alpha_thread, NULL);
    pthread_join(num_threadl, NULL);
    return 0;
}