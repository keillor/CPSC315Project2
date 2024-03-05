#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int currentIndex = 1;
int arrayLength;

void *alpha(char* myStr[]) {
    printf("alpha: %s\n", myStr[currentIndex]);
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