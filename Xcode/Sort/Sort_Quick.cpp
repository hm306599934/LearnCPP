//
//  QuickSort.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/20.
//  Copyright © 2019 Airactart. All rights reserved.
//
//  快速排序

#include "Header.hpp"

namespace Jimmy {

    int sort_quickPartion(vector<int> &vec, int l, int r) {
        int x = vec[l];
        int i = l, k = l;
        for (int j = l+1; j <= r; j++) {
            if (vec[j] <= x) {
                swapVector(vec,i,j);
                i++;
                k = j;
            }
        }

        if(vec[i] != x) {
            swapVector(vec,i,k);
        }

        return i;
    }

    void sort_quickHelper(vector<int> &vec, int l, int r) {
        if (l < r) {
            int p = sort_quickPartion(vec, l, r);
            sort_quickHelper(vec, l, p-1);
            sort_quickHelper(vec, p+1, r);
        }
    }

    // i是基准位, 将大于vec[i]的放在右边, 小于i的放在左边
    // 然后对左右边进行递归排序
    void Sort::main_quick() {
        vector<int> v1{4,12,2,6,3,18,2,19,23,13,8,6,7,16,5,12,4};
        vector<int> v2{9,6,7,16,5,12,4};
        vector<int> v3 = getVectorInt(20);

        printVector(v3);
        sort_quickHelper(v3, 0, (int)v3.size()-1);
        printVector(v3);
    }
}
