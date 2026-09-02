#include <iostream>

using namespace std;

int minVal(int a, int b) {
    return (a < b) ? a : b;
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortRecursive(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void mergeSortIterative(int arr[], int n) {
    for (int curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = minVal(left_start + curr_size - 1, n - 1);
            int right_end = minVal(left_start + 2 * curr_size - 1, n - 1);

            merge(arr, left_start, mid, right_end);
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[n];
    for (int i = 0; i < n; i++) {
        arr2[i] = arr1[i];
    }

    cout << "Recursive Merge Sort:" << endl;
    mergeSortRecursive(arr1, 0, n - 1);
    printArray(arr1, n);

    cout << "\nIterative Merge Sort:" << endl;
    mergeSortIterative(arr2, n);
    printArray(arr2, n);

    return 0;
}
