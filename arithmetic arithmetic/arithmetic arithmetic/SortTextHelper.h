//
//  SortTextHelper.h
//  111
//
//  Created by 每天农资 on 2017/12/12.
//  Copyright © 2017年 我是五高你敢信. All rights reserved.
//

#ifndef SortTextHelper_h
#define SortTextHelper_h

#include <iostream>
#include <cassert>
using namespace std;

namespace SortTextHelper {
    
    int* generateRandomArray(int n, int rangeL, int rangeR) {
        
        assert(rangeL <= rangeR);
        
        int *arr = new int[n];
        
        srand(time(NULL));
        
        for (int i=0; i<n; i++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        
        return arr;
    }
    
    int* generateNerlyOrderArray(int n, int swapTimes) {
        
        int *arr = new int[n];
        for (int i=0; i<n; i++) {
            arr[i] = i;
        }
        
        srand(time(NULL));
        for (int i=0; i<swapTimes; i++) {
            int posX = rand() % n;
            int posY = rand() % n;
            swap(arr[posX], arr[posY]);
        }
        
        return arr;
    }
    
    template< typename T>
    void printArray(T arr[], int n) {
        for (int i=0; i<n; i++) {
            cout << arr[i] << " ";
        }
        return;
    }
    
    template< typename T>
    bool isSort(T arr[], int n) {
        for (int i=0; i<n-1; i++) {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }
    
    template< typename T>
    void sortTimeTest( string sortName, void(*sort)(T arr[], int n), T arr[], int n) {
        
        clock_t startime = clock();
        
        sort(arr, n);
        
        clock_t endtime = clock();
        
        assert( isSort(arr, n));
        cout<< sortName << " : " << double(endtime - startime) / CLOCKS_PER_SEC << " s ";
        
        return;
    }
    
    int* copyIntArray(int a[], int n) {
        int *arr = new int[n];
        copy(a, a+n, arr);
        return arr;
    }
}
#endif /* SortTextHelper_h */
