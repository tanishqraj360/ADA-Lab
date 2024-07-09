#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int low, int mid, int high) {
  int i, j, k;
  int n1 = mid - low + 1;
  int n2 = high - mid;

  int left[n1], right[n2];

  for (int i = 0; i < n1; i++) {
    left[i] = arr[low + i];
  }
  for (j = 0; j < n2; j++) {
    right[j] = arr[mid + 1 + j];
  }

  i = 0;
  j = 0;
  k = low;

  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = left[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = right[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
  }
}

int main() {
  int n;
  clock_t start, end;
  double cpu_time_used;
  printf("\nEnter range: \n");
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    a[i] = rand();
  }

  start = clock();
  mergeSort(a, 0, n - 1);
  end = clock();

  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
  printf("\nTime taken: %f\n", cpu_time_used);
}
