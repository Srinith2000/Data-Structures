#include<stdio.h>
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    selection_sort(arr, n);
    printf("Sorted array: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}