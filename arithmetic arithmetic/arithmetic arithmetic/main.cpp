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

//如果没找到target 返回-1
template <typename T>
int binarySearch(T arr[], int n, T target) {
    
    //在arr[l...r]中寻找target
    int l= 0, r = n - 1;
    while (l <= r ) {
        
        int mid = (l + r) / 2;
        if (arr[mid] == target)
            return mid;
        if (target < mid)
            r = mid - 1; 
        else
            l = mid + 1;
    }
}


//MARK: - main函数
int main(int argc, const char * argv[]) {
    
//    testSort(10000);
    
   
    
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

template <typename Value, typename Key>
class BST {
private:
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;
        
        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };
    
    Node *root;
    int count;
    
public:
    BST() {
        root = NULL;
        count = 0;
    }
    
    ~BST() {
        // TODO:
    }
    
    int size() {
        return count;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    void insert(Key key, Value value) {
        root = insert(root, key, value);
    }
    
private:
    Node* insert(Node *node, Key key, Value value) {
        if (node == NULL) {
            count++;
            return new Node(key, value);
        }
        
        if (key == node->key)
            node->value = value;
        else if (key < node->key)
            node->left = insert(node->left, key, value);
        else
            node->right = insert(node->right, key, value);
        
        return node;
    }
    
};

