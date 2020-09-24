//  Created by Дарья Землянская on 23.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void Print(const std::vector <int> &a){
    for (int i : a){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void merge(std::vector <int> &a, int l, int m, int r)
{
    int i, j;
  std::vector<int> v2 (r-l+1);
    for (i = m+1; i > l; i--){
        v2[i-1] = a[i-1];
    }
    for (j = m; j < r; j++){
        v2[r+m-j] = a[j+1];
    }
  for (int k = l; k <= r; k++) {
      if (v2[i] > v2[j])
          a[k] = v2[j--];
      else
          a[k] = v2[i++];
  }
}

void mergeSort(std::vector <int> &a, int l, int r)
{
  if (l == r) return;
  int mid = (l + r) / 2;
  mergeSort(a, l, mid);
  mergeSort(a, mid + 1, r);
  merge(a, l, mid, r);
}

int main(){
    size_t n;
    std::cout << "Number of vector elements: ";
    std::cin >> n;
    std::vector<int> a(n);
    std::cout << "Elements: ";
    for (int i = 0; i < n; ++i){
        std::cin >> a[i];
    }
    mergeSort(a, 0, (a.size() - 1)); // вызываем функцию сортировки
    Print(a);
  return 0;
}
