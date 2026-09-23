#include<stdio.h>
#include<stdlib.h>
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *larr = (int *)malloc(sizeof(int) * n1);
    int *rarr = (int *)malloc(sizeof(int) * n2);
    for (i = 0; i < n1; i++) {
        larr[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        rarr[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (larr[i] <= rarr[j]) {
            arr[k] = larr[i];
            i = i + 1;
        }
        else {
            arr[k] = rarr[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i < n1) {
        arr[k] = larr[i];
        i = i + 1;
        k = k + 1;
    }
    while (j < n2) {
        arr[k] = rarr[j];
        j = j + 1;
        k = k + 1;
    }
    free(larr);
    free(rarr);
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1 , r);
        merge(arr, l, m, r);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}