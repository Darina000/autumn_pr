//
//  main.cpp
//  task2
//
//  Created by Дарья Землянская on 20.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

void Print(const std::vector <int> &a){
    for (int i : a){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void mergeSort(std::vector <int> &a, int l, int r)
{
  if (l == r) return;
  int mid = (l + r) / 2;
  mergeSort(a, l, mid);
  mergeSort(a, mid + 1, r);
  int i = l;
  int j = mid + 1;
    std::vector<int> tmp (5);
    for (int step = 0; step < r - l + 1; step++)
    {
        if ((j > r) || ((i <= mid) && (a[i] < a[j])))
        {
            tmp[step] = a[i];
            i++;
            
        }else
        {
            tmp[step] = a[j];
            j++;
        }
        
    }
  for (int step = 0; step < r - l + 1; step++)
    a[l + step] = tmp[step];
}

int main(){
    size_t n;
    std::cout << "Number of vector elements: ";
    std::cin >> n;
    std::vector<int> a(n);
    std::cout << "Elements: ";
    for (int i; i < n; ++i){
        std::cin >> a[i];
    }
    mergeSort(a, 0, (a.size() - 1)); // вызываем функцию сортировки
    Print(a);
  return 0;
}
