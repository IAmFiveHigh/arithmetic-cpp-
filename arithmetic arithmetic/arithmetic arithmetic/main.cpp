//
//  main.cpp
//  arithetic
//
//  Created by 每天农资 on 2017/10/31.
//  Copyright © 2017年 我是五高你敢信. All rights reserved.
//

#include <iostream>
#include "SortTextHelper.h"
#include "MaxHeap.h"

using namespace std;

//选择排序
template <typename T>
void selectionSort( T arr[], int n) {
    
    
    for (int i = 0 ; i < n ; i ++) {
        int minIndex = i;
        
        for (int j = i; j < n; j ++)
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        
        swap(arr[minIndex], arr[i]);
    }
}

//冒泡排序
template <typename T>
void bubbleSort( T arr[], int n) {
    
    for (int i=0; i<n; i++) {
        
        for (int j=0; j<n-i-1; j++) {
            
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

//插入排序
template <typename T>
void insertSort( T arr[], int n) {
    
    for (int i=1; i<n; i++) {
        
        T b = arr[i];
        int j;
        for (j=i; j>0 && arr[j-1] > b; j--) {
            arr[j] = arr[j-1];
        }
        
        arr[j] = b;
    }
}

//归并排序
template <typename T>
void __merge(T arr[], int l, int mid, int r) {
    
    T aux[r - l + 1];
    for (int i=l; i<=r; i++) {
        aux[i-l] = arr[i];
    }
    
    int i=l, j=mid+1;
    for (int k=l; k<=r; k++) {
        
        if (i > mid) {
            
            arr[k] = aux[j-l];
            j++;
        }else if (j > r) {
            
            arr[k] = aux[i-l];
            i++;
        }else if (aux[i-l] < aux[j-l]) {
            
            arr[k] = aux[i-l];
            i++;
        }else {
            
            arr[k] = aux[j-l];
            j++;
        }
    }
}

template <typename T>
void  __mergeSort(T arr[], int l, int r) {
    
    if (l >= r) {
        return;
    }
    
    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    
    if (arr[mid] > arr[mid + 1]) {
        __merge(arr, l, mid, r);
    }
    
}

template <typename T>
void mergeSort(T arr[], int n) {
    
    __mergeSort(arr, 0, n-1);
}

template <typename T>
void mergeSortBU(T arr[], int n) {
    
    __mergeSort(arr, 0, n-1);
}

//快速排序
template <typename T>
int __partite(T arr[], int l, int r) {
    
    swap(arr[rand()%(r - l + 1) + l], arr[l]);
    T v = arr[l];
    
    int j = l;
    for (int i=l+1; i<=r; i++) {
        if (arr[i] < v) {
            swap(arr[i], arr[j+1]);
            j++;
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

template <typename T>
void __quickSort(T arr[], int l, int r) {
    
    if (l >= r) {
        return;
    }
    
    int p = __partite(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n) {
    
    srand(time(NULL));
    
    __quickSort(arr, 0, n-1);
}

//快速排序优化
template <typename T>
int __partition2(T arr[], int l, int r) {
    
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    
    int i=l+1, j=r;
    while (true) {
        while (arr[i]<v && i<=r) {
            i++;
        }
        while (arr[j]>v && j>=l+1) {
            j--;
        }
        
        if (i>j) {
            break;
        }
        
        swap(arr[i], arr[j]);
        i++;
        j--;
        
    }
    swap(arr[l], arr[j]);
    return j;
}

template <typename T>
void __quickSort2(T arr[], int l, int r) {
    
    if (l >= r) {
        return;
    }
    
    int p = __partition2(arr, l, r);
    __quickSort2(arr, l, p-1);
    __quickSort2(arr, p+1, r);
}

template <typename T>
void quickSort2(T arr[], int n) {
    
    srand(time(NULL));
    __quickSort2(arr, 0, n-1);
}

//三路快速排序
template <typename T>
void __quickSortThreeWays(T arr[], int l, int r) {
    
    if (l > r) {
        return;
    }
    
    //partition
    swap(arr[l], arr[rand()%(r - l + 1) + l]);
    T v = arr[l];
    
    int lt = l;
    int gt = r+1;
    int i=l+1;
    while (i<gt) {
        if (arr[i] < v) {
            swap(arr[i], arr[lt+1]);
            lt++;
            i++;
        }else if (arr[i] > v) {
            swap(arr[i], arr[gt-1]);
            gt--;
        }else {
            i++;
        }
    }
    
    swap(arr[l], arr[lt]);
    __quickSortThreeWays(arr, l, lt-1);
    __quickSortThreeWays(arr, gt, r);
}

template <typename T>
void quickSortThreeWays(T arr[], int n) {
    
    srand(time(NULL));
    __quickSortThreeWays(arr, 0, n-1);
}

void testSort(int n);

template <typename T>
void heapSort1(T arr[], int n) {
    
    MaxHeap<T> maxHeap = MaxHeap<T>(n);
    for (int i=0; i<n; i++) {
        maxHeap.insert(arr[i]);
    }
    
    for (int i=n-1; i>=0; i--) {
        arr[i] = maxHeap.extractMax();
    }
}

template <typename T>
void heapSort2(T arr[], int n) {
    MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);
    for (int i=n-1; i>=0; i--) {
        arr[i] = maxHeap.extractMax();
    }
}

//MARK: - main函数
int main(int argc, const char * argv[]) {
    
//    testSort(10000);
    
    cout<<endl;
    cout<<"普通乱序数组";
    cout<<endl;
    
    int n = 100000;
    int *arr1 = SortTextHelper::generateRandomArray(n, 0, 10000);
    int *arr2 = SortTextHelper::copyIntArray(arr1, n);
    int *arr3 = SortTextHelper::copyIntArray(arr1, n);
    int *arr4 = SortTextHelper::copyIntArray(arr1, n);
    int *arr5 = SortTextHelper::copyIntArray(arr1, n);

    SortTextHelper::sortTimeTest("快速排序", quickSort, arr1, n);
    SortTextHelper::sortTimeTest("快速三路排序", quickSortThreeWays, arr2, n);
    SortTextHelper::sortTimeTest("归并排序", mergeSort, arr3, n);
    SortTextHelper::sortTimeTest("堆排序", heapSort1, arr4, n);
    SortTextHelper::sortTimeTest("堆排序2", heapSort2, arr5, n);

    
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
    delete [] arr5;
    
    cout<<endl;
    cout<<"近乎有序数组";
    cout<<endl;
    
    arr1 = SortTextHelper::generateNerlyOrderArray(n, 100);
    arr2 = SortTextHelper::copyIntArray(arr1, n);
    arr3 = SortTextHelper::copyIntArray(arr1, n);
    arr4 = SortTextHelper::copyIntArray(arr1, n);
    arr5 = SortTextHelper::copyIntArray(arr1, n);

    SortTextHelper::sortTimeTest("快速排序", quickSort, arr1, n);
    SortTextHelper::sortTimeTest("快速三路排序", quickSortThreeWays, arr2, n);
    SortTextHelper::sortTimeTest("归并排序", mergeSort, arr3, n);
    SortTextHelper::sortTimeTest("堆排序", heapSort1, arr4, n);
    SortTextHelper::sortTimeTest("堆排序2", heapSort2, arr5, n);

    
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
    delete [] arr5;
    
    cout<<endl;
    cout<<"大量重复数组";
    cout<<endl;
    
    arr1 = SortTextHelper::generateRandomArray(n, 0, 10);
    arr2 = SortTextHelper::copyIntArray(arr1, n);
    arr3 = SortTextHelper::copyIntArray(arr1, n);
    arr4 = SortTextHelper::copyIntArray(arr1, n);
    arr5 = SortTextHelper::copyIntArray(arr1, n);

    SortTextHelper::sortTimeTest("快速排序", quickSort, arr1, n);
    SortTextHelper::sortTimeTest("快速三路排序", quickSortThreeWays, arr2, n);
    SortTextHelper::sortTimeTest("归并排序", mergeSort, arr3, n);
    SortTextHelper::sortTimeTest("堆排序", heapSort1, arr4, n);
    SortTextHelper::sortTimeTest("堆排序2", heapSort2, arr5, n);

    
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
    delete [] arr5;
    
    return 0;
}


void testSort(int n) {

    int *arr = SortTextHelper::generateRandomArray(n, 0, 10000);
    int *arr2 = SortTextHelper::copyIntArray(arr, n);
    int *arr3 = SortTextHelper::copyIntArray(arr, n);
    int *arr4 = SortTextHelper::copyIntArray(arr, n);
    int *arr5 = SortTextHelper::copyIntArray(arr, n);
    int *arr6 = SortTextHelper::copyIntArray(arr, n);
    int *arr7 = SortTextHelper::copyIntArray(arr, n);
    
    
    SortTextHelper::sortTimeTest("冒泡排序", bubbleSort, arr4, n);
    
    cout<<endl;
    SortTextHelper::sortTimeTest("选择排序", selectionSort, arr3, n);
    
    cout<<endl;
    SortTextHelper::sortTimeTest("插入排序", insertSort, arr, n);
    
    cout<< endl;
    SortTextHelper::sortTimeTest("归并排序", mergeSort, arr2, n);
    
    cout<< endl;
    SortTextHelper::sortTimeTest("快速排序", quickSort, arr5, n);
    
    cout<< endl;
    SortTextHelper::sortTimeTest("优化快速排序", quickSort2, arr6, n);
    
    cout<< endl;
    SortTextHelper::sortTimeTest("三路优化快速排序", quickSortThreeWays, arr7, n);
    
    cout<< endl;
    delete [] arr;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
    delete [] arr5;
    delete [] arr6;
    delete [] arr7;

}

