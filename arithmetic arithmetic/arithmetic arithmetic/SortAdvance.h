//
//  SortAdvance.h
//  arithmetic arithmetic
//
//  Created by 每天农资 on 2018/1/17.
//  Copyright © 2018年 我是五高你敢信. All rights reserved.
//

#ifndef SortAdvance_h
#define SortAdvance_h

#include <iostream>

using namespace std;

namespace SortAdvance {
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
    
    
}

#endif /* SortAdvance_h */
