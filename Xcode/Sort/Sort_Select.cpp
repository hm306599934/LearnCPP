//
//  Sort_Select.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/6.
//  Copyright © 2019 Jimmy. All rights reserved.
//
//  选择排序

#include "Header.hpp"

namespace Jimmy {

    void sort_select(vector<int> &vec) {
        for (int i = 0; i < vec.size()-1; i ++) {
            int min = i;
            for (int j = i + 1; j < vec.size(); j ++) {
                if (vec[j] < vec[min]) {
                    min = j;
                }
            }
            int temp = vec[i];
            vec[i] = vec[min];
            vec[min] = temp;
        }
    }

    // 每次找到最小的，将最小的元素和当前元素交换
    // 以此类推
    void Sort::main_select() {
        vector<int> v1{4,12,2,6,3,18,2,19,23,13,8,6,7,16,5,12,4};
        vector<int> v2{9,6,7,16,5,12,4};
        vector<int> v3 = getVectorInt(20);

        printVector(v3);
        sort_select(v3);
        printVector(v3);
    }
}
