#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int i, n, j = 0, k = MAX_SIZE - 1;

    printf("Enter integers (-1 to stop):\n");
    while (scanf("%d", &n) == 1 && n != -1) {
        if (n % 2 == 0) {
            arr[k--] = n;
        } else {
            arr[j++] = n;
        }
    }

    printf("The resulting array is:\n");
    for (i = 0; i < j; ++i) {
        printf("%d ", arr[i]);
    }
    for (i = MAX_SIZE - 1; i > k; --i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
