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
    
public:
    MaxHeap(int capacity) {
        data = new Item[capacity + 1];
        count = 0;
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
};

#endif /* MaxHeap_h */
