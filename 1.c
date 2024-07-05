#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int a[], int n) {
  int i, j, min;
  for (i = 0; i < n; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }

    int temp = a[min];
    a[min] = a[i];
    a[i] = temp;
  }
}

int main() {
  int n, a[200000];
  clock_t start, end;
  double cpu_time_used;
  printf("\n Enter how many numbers: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    a[i] = rand();
  }
  start = clock();
  selectionSort(a, n);
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
  printf("\n Time Taken: %f", cpu_time_used);
}
