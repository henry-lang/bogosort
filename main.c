#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 12
// #define OUTPUT

int arr[N];
unsigned long iters;

static inline void print_arr() {
    printf("Iteration %lu: [ ", iters);
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}

static inline int sorted() {
    for(int i = 0; i < N - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

static inline void shuffle() {
    for (int i = N - 1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    srand(time(NULL));

    for(int i = 0; i < N; i++) {
        arr[i] = (rand() % 100) - 50;
        // printf("%d\n", arr[i]);
    }

    while(!sorted()) {
        shuffle();
#ifdef OUTPUT
        print_arr();
#endif
        ++iters;
    }

    print_arr();

    return 0;
}