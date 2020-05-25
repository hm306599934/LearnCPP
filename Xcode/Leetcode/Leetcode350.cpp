//
//  Leetcode350.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/31.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // 排序
    // 对小的数组下手
    // 双指针
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> big = nums1;
        vector<int> small = nums2;
        if (nums2.size() > nums1.size()) {
            big = nums2;
            small = nums1;
        }

        vector<int> res;
        int j = 0;
        for (int i = 0;i < small.size();i++) {
            cout << "i: " << i << " j: " << j<<endl;
            while (j < big.size() && big[j] < small[i]) j++;
            if (j < big.size() && big[j] == small[i]) {
                res.push_back(small[i]);
                j++;
            }
            if (j >= big.size()) {
                break;
            }
        }
        return res;
    }

    // 寻找交集
    void Leetcode::main_350() {
//        vector<int> v1{1,2,2,1};
//        vector<int> v2{2,2};
//        printVector(intersect(v1, v2));
//        vector<int> v3{4,9,5};
//        vector<int> v4{9,4,9,8,4};
//        printVector(intersect(v3, v4));
//        vector<int> v5{1,2};
//        vector<int> v6{1,1};
//        printVector(intersect(v5, v6));
        vector<int> v7{4,7,9,7,6,7};
        vector<int> v8{5,0,0,6,1,6,2,2,4};
        printVector(intersect(v7, v8));
    }
}

