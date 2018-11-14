#include <iostream>
using namespace std;

void merge(int [], int, int [], int, int []);

int main() {
  int a[100], b[100], m, n, c, sorted[200];

  cout<<"Input number of elements in first array\n";
  cin>>m;

  cout<<"Input %d integers\n"<<m;
  for (c = 0; c < m; c++) {
    cin>>a[c];
  }

  cout<<"Input number of elements in second array\n";
  cin>>n;

  cout<<"Input %d integers\n"<<n;
  for (c = 0; c < n; c++) 
  {
    cin>>b[c];
  }

  merge(a, m, b, n, sorted);

  printf("Sorted array:\n");

  for (c = 0; c < m + n; c++) {
    printf("%d\n", sorted[c]);
  }

  return 0;
}

void merge(int a[], int m, int b[], int n, int sorted[]) {
  int i, j, k;

  j = k = 0;

  for (i = 0; i < m + n;) {
    if (j < m && k < n) {
      if (a[j] < b[k]) {
        sorted[i] = a[j];
        j++;
      }
      else {
        sorted[i] = b[k];
        k++;
      }
      i++;
    }
    else if (j == m) {
      for (; i < m + n;) {
        sorted[i] = b[k];
        k++;
        i++;
      }
    }
    else {
      for (; i < m + n;) {
        sorted[i] = a[j];
        j++;
        i++;
      }
    }
  }
}

