//
//  Sort_Insert.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/6.
//  Copyright © 2019 Jimmy. All rights reserved.
//
//  插入排序

#include "Header.hpp"

namespace Jimmy {

    void sort_insert(vector<int> &vec) {
        for (int i = 1; i < vec.size(); i ++) {
            for (int j = i; j > 0 && vec[j] < vec[j-1]; j--) {
                swapVec(vec, j-1, j);
            }
        }
    }

    // 先将前i个排好序，然后插入第i+1个
    // 对第i个元素，前i-1个元素都是有序的，只需要不断前移即可
    // 以此类推
    void Sort::main_insert() {
        vector<int> v1{4,12,2,6,3,18,2,19,23,13,8,6,7,16,5,12,4};
        vector<int> v2{9,6,7,16,5,12,4};
        vector<int> v3 = getVectorInt(20);

        printVector(v3);
        sort_insert(v3);
        printVector(v3);
    }
}
