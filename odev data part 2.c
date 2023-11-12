#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main() {
    int numbers[SIZE];
    int i, j, temp;

    srand(time(NULL));

    for (i = 0; i < SIZE; i++) {
        numbers[i] = rand();
    }

    for (i = 0; i < SIZE - 1; i++) {
        for (j = i + 1; j < SIZE; j++) {
            if (numbers[i] < numbers[j]) {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    printf("The sorted list of random numbers is:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}
