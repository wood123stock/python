#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_Array(int *m, int *a) {
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *m - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            } else if (a[j] == a[j + 1]) {
                a[j + 1] = -999999;
                //(*m)--;
            }
        }
    }

    // Remove duplicates by reallocating memory
    //a = realloc(a, (*m) * sizeof(int));
}

int main() {
    int n;
    scanf("%d", &n);

    int *Arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &Arr[i]);
    }

    sort_Array(&n, Arr);

    printf("%d\n", n);

    for (int i = 0; i < n; i++) {
        printf("%d ", Arr[i]);
    }

    free(Arr); // Free the allocated memory
    return 0;
}
