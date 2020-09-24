//  Created by Дарья Землянская on 23.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
void merge(std::vector <int> &arr, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
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
void mergeSort(std::vector <int> &arr, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void Print(const std::vector <int> &a){
    for (int i : a){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
  
int main()
{
    int n;
    std::cout << "Number of vector elements: ";
    std::cin >> n;
    std::vector<int> arr(n);
    std::cout << "Elements: ";
    for (int i = 0; i < n; ++i){
        std::cin >> arr[i];
    }
    int arr_size = arr.size();
  
    mergeSort(arr, 0, arr_size - 1);
  
    std::cout << "Vector after sort: ";
    Print(arr);
    return 0;
}
