#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int currentIndex = 1;
int arrayLength;

void *alpha(char* myStr[]) {
    int iterationIndex = currentIndex;
    if(myStr[currentIndex][0] > 47 && myStr[currentIndex][0] < 58) {
        printf("alpha: %s\n", myStr[currentIndex]);
        currentIndex++;
        if(currentIndex >= arrayLength) {
            return NULL;
        }
    }
    /*while (iterationIndex == currentIndex) {
        continue;
    }*/
    return NULL;
}

void *numeric(char* myStr[]) {
    printf("numeric: %s\n", myStr[currentIndex]);
    return NULL;
}

int main(int argc, char* argv[]) {
    arrayLength = sizeof(argv);
    pthread_t alpha_thread, num_threadl;
    pthread_create(&alpha_thread, NULL, alpha, argv);
    pthread_join(alpha_thread, NULL);
    return 0;
}