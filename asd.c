#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_Array(int m, int *a) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
            // No need for the else if block if not using it
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int Arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &Arr[i]);
    }

    sort_Array(n, Arr);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", Arr[i]);
    }

    return 0;
}
