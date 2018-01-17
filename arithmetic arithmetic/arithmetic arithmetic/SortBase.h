//
//  SortBase.h
//  arithmetic arithmetic
//
//  Created by 每天农资 on 2018/1/17.
//  Copyright © 2018年 我是五高你敢信. All rights reserved.
//

#ifndef SortBase_h
#define SortBase_h

#include <iostream>

using namespace std;

namespace SortBase {
    
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
}


#endif /* SortBase_h */
