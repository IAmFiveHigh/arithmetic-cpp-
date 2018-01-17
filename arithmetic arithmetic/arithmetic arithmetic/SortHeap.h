//
//  SortHeap.h
//  arithmetic arithmetic
//
//  Created by 每天农资 on 2018/1/17.
//  Copyright © 2018年 我是五高你敢信. All rights reserved.
//

#ifndef SortHeap_h
#define SortHeap_h

#include <iostream>

using namespace std;

namespace SortHeap {
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
}

#endif /* SortHeap_h */
