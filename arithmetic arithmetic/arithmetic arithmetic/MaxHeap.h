//
//  MaxHeap.h
//  arithmetic arithmetic
//
//  Created by 每天农资 on 2017/12/19.
//  Copyright © 2017年 我是五高你敢信. All rights reserved.
//

#ifndef MaxHeap_h
#define MaxHeap_h

using namespace std;

template <typename Item>
class MaxHeap {
    
    
private:
    Item* data;
    int count;
    int capacity;
    
    void shiftUp(int k) {
        while (k>1 && data[k/2] < data[k]) {
            swap(data[k/2], data[k]);
            k/=2;
        }
    }
    
public:
    MaxHeap(int capacity) {
        data = new Item[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }
    
    ~MaxHeap() {
        delete [] data;
    }
    
    int size() {
        return count;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    void insert(Item item) {
        
        assert(count + 1 <= capacity);
        
        data[count + 1] = item;
        count ++;
        shiftUp(count);
    }
};

#endif /* MaxHeap_h */
