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
#include "SortBase.h"
#include "SortAdvance.h"
#include "SortHeap.h"
using namespace std;



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

    SortTextHelper::sortTimeTest("快速排序", SortAdvance::quickSort, arr1, n);
    SortTextHelper::sortTimeTest("快速三路排序", SortAdvance::quickSortThreeWays, arr2, n);
    SortTextHelper::sortTimeTest("归并排序", SortAdvance::mergeSort, arr3, n);
    SortTextHelper::sortTimeTest("堆排序", SortHeap::heapSort1, arr4, n);
    SortTextHelper::sortTimeTest("堆排序2", SortHeap::heapSort2, arr5, n);
//
//
//    delete [] arr1;
//    delete [] arr2;
//    delete [] arr3;
//    delete [] arr4;
//    delete [] arr5;
//
//    cout<<endl;
//    cout<<"近乎有序数组";
//    cout<<endl;
//
//    arr1 = SortTextHelper::generateNerlyOrderArray(n, 100);
//    arr2 = SortTextHelper::copyIntArray(arr1, n);
//    arr3 = SortTextHelper::copyIntArray(arr1, n);
//    arr4 = SortTextHelper::copyIntArray(arr1, n);
//    arr5 = SortTextHelper::copyIntArray(arr1, n);
//
//    SortTextHelper::sortTimeTest("快速排序", SortAdvance::quickSort, arr1, n);
//    SortTextHelper::sortTimeTest("快速三路排序", SortAdvance::quickSortThreeWays, arr2, n);
//    SortTextHelper::sortTimeTest("归并排序", SortAdvance::mergeSort, arr3, n);
//    SortTextHelper::sortTimeTest("堆排序", SortHeap::heapSort1, arr4, n);
////    SortTextHelper::sortTimeTest("堆排序2", SortHeap::heapSort2, arr5, n);
//
//
//    delete [] arr1;
//    delete [] arr2;
//    delete [] arr3;
//    delete [] arr4;
//    delete [] arr5;
//
//    cout<<endl;
//    cout<<"大量重复数组";
//    cout<<endl;
//
//    arr1 = SortTextHelper::generateRandomArray(n, 0, 10);
//    arr2 = SortTextHelper::copyIntArray(arr1, n);
//    arr3 = SortTextHelper::copyIntArray(arr1, n);
//    arr4 = SortTextHelper::copyIntArray(arr1, n);
//    arr5 = SortTextHelper::copyIntArray(arr1, n);
//
//    SortTextHelper::sortTimeTest("快速排序", SortAdvance::quickSort, arr1, n);
//    SortTextHelper::sortTimeTest("快速三路排序", SortAdvance::quickSortThreeWays, arr2, n);
//    SortTextHelper::sortTimeTest("归并排序", SortAdvance::mergeSort, arr3, n);
//    SortTextHelper::sortTimeTest("堆排序", SortHeap::heapSort1, arr4, n);
////    SortTextHelper::sortTimeTest("堆排序2", SortHeap::heapSort2, arr5, n);
//
//
//    delete [] arr1;
//    delete [] arr2;
//    delete [] arr3;
//    delete [] arr4;
//    delete [] arr5;
    
//    MaxHeap<int> maxheap = MaxHeap<int>(100);
//    srand(time(NULL));
//
//    for (int i=0; i<50; i++) {
//        maxheap.insert(rand()%100);
//    }
//
//    for (int i=0; i<50; i++) {
//        cout<<maxheap.extractMax()<<endl;
//    }
    
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
    
    
    SortTextHelper::sortTimeTest("冒泡排序", SortBase::bubbleSort, arr4, n);
    
    cout<<endl;
    SortTextHelper::sortTimeTest("选择排序", SortBase::selectionSort, arr3, n);
    
    cout<<endl;
    SortTextHelper::sortTimeTest("插入排序", SortBase::insertSort, arr, n);
    
    cout<< endl;
    SortTextHelper::sortTimeTest("归并排序", SortAdvance::mergeSort, arr2, n);
    
    cout<< endl;
    SortTextHelper::sortTimeTest("快速排序", SortAdvance::quickSort, arr5, n);
    
    cout<< endl;
    SortTextHelper::sortTimeTest("优化快速排序", SortAdvance::quickSort2, arr6, n);
    
    cout<< endl;
    SortTextHelper::sortTimeTest("三路优化快速排序", SortAdvance::quickSortThreeWays, arr7, n);
    
    cout<< endl;
    delete [] arr;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
    delete [] arr5;
    delete [] arr6;
    delete [] arr7;

}

