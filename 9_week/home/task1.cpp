//  Created by Дарья Землянская on 23.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//
#include <iostream>
#include <vector>
#include <functional>
#include <utility>


template<typename T>
void Merge(T *arr, int start, int end, const std::function<bool()>& fn)
{
    int z, x, y, mid;
    std::vector<T> temp(end -start + 1);
    mid = (start + end) / 2;
    z = 0;
    x = start;
    y = mid + 1;

    while (x <= mid && y <= end)
    {
        if (fn()){
            if  ((arr[x] > arr[y]))
                {
                    temp[z] = arr[x];
                    ++x;
                    ++z;
                }
            else{
                    temp[z] = arr[y];
                    ++y;
                    ++z;
                }
        }else{
            if  ((arr[x] < arr[y]))
                {
                    temp[z] = arr[x];
                    ++x;
                    ++z;
                }
            else
                {
                    temp[z] = arr[y];
                    ++y;
                    ++z;
                }
        }
    }
    
    while (x <= mid)
    {
        temp[z] = arr[x];
        ++x;
        ++z;
    }
    while (y <= end)
    {
        temp[z] = arr[y];
        ++y;
        ++z;
    }
    for (int i = start; i <= end; ++i)
    {
        arr[i] = temp[i - start];
    }

}

template<typename T>
void mergeSort(T *arr, int l, int r, const std::function<bool()>& fn)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid, fn);
        mergeSort(arr, mid + 1, r, fn);
        Merge(arr, l, r, fn);
    }
}


template<typename T>
void Print(T *arr, std::size_t N)
{
    for (int i = 0; i < N; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

template<typename T, std::size_t N>
void Print(T (&arr) [N])
{
    for (int i = 0; i < N; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int arr1[] = { 1, 11, 9, 14, 3, 2, 20, 19, 10, 10, 90, -32, 100, -1};
    int n = sizeof(arr1) / sizeof(int);

    std::cout << "Array Before Sorting: " << std::endl;
    Print(arr1);
    mergeSort(arr1, 0, n - 1, [](){return false;});

    std::cout << "Array After Sorting: " << std::endl;
    Print(arr1);

    std::size_t m = 5;
    int *arr2 = new int[m] { 2, 1, 4, 7, 3 };
    
    std::cout << "Array Before Sorting: " << std::endl;
    Print(arr2, m);
    mergeSort(arr2, 0, m - 1, [](){return false;});

    std::cout << "Array After Sorting: " << std::endl;
    Print(arr2, m);
    
    delete [] arr2;
}
