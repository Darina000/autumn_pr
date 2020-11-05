//  Created by Дарья Землянская on 23.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//
#include<iostream>
#include<vector>

template <typename T>
class standart_cmp
{
public:
static bool less(bool sort, const T &a, const T &b)
    {
        if (sort){
            return a < b;
        }
        return a > b;
    }
};

template<typename T, typename cmp = standart_cmp<T>>
void Merge(bool s, T *arr, int start, int end)
{
    int z, x, y, mid;
    std::vector<T> temp(end -start + 1);
    mid = (start + end) / 2;
    z = 0;
    x = start;
    y = mid + 1;

    while (x <= mid && y <= end)
    {
        if (cmp::less(s, arr[x], arr[y]))
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
void mergeSort(bool s, T *arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(s, arr, l, mid);
        mergeSort(s, arr, mid + 1, r);
        Merge(s, arr, l, r);
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
    bool s = false;
    int arr1[] = { 1, 10, 10, 90, -32, 100, -1, 11, 9, 14, 3, 2, 20, 19 };
    int n = sizeof(arr1) / sizeof(int);

    std::cout << "Array Before Sorting: " << std::endl;
    Print(arr1);
    mergeSort(s, arr1, 0, n - 1);

    std::cout << "Array After Sorting: " << std::endl;
    Print(arr1);

    std::size_t m = 5;
    int *arr2 = new int[m] { 2, 1, 4, 7, 3 };
    
    std::cout << "Array Before Sorting: " << std::endl;
    Print(arr2, m);
    mergeSort(s, arr2, 0, m - 1);

    std::cout << "Array After Sorting: " << std::endl;
    Print(arr2, m);
    
    delete [] arr2;
}
