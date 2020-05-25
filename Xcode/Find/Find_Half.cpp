//
//  Find_Half.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/21.
//  Copyright © 2019 Airactart. All rights reserved.
//
//  二分法查找

#include "Header.hpp"

namespace Jimmy {

    int find_halfHelper(vector<int> &vec, int key, int l, int r) {
        if (l >= r) return -1;
        int mid = (l + r) / 2;
        int x = vec[mid];

        if (x == key) {
            return mid;
        } else if (x > key) {
            return find_halfHelper(vec, key, l, mid-1);
        } else {
            return find_halfHelper(vec, key, mid+1, r);
        }
    }

    void Find::main_half() {
        vector<int> vec1{1,4,5,8,12,54,122,222};
        cout << find_halfHelper(vec1, 9, 0, (int)vec1.size()-1) << endl;;

    }
}
