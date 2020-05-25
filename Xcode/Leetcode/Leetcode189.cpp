//
//  Leetcode189.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/19.
//  Copyright © 2019 Airactart. All rights reserved.
//
//  给定一个数组和一个数字n, 进行n次操作, 每次都将数组的最后一个数字放到最前面.

#include "Header.hpp"

namespace Jimmy {

    void rotate2(vector<int>& nums, int k) {
        int n = (int)nums.size();
        k = k % n;
        vector<int> first = vector<int>(nums.begin()+(n-k), nums.end());
        first.insert(first.end(), nums.begin(), nums.begin()+(n-k));
        nums = first;
    }

    void rotate(vector<int>& nums, int k)
    {
        int n = (int)nums.size();
        k = k % n;
        if (k > n-k) {
            // 前面移到后面
            vector<int> temp = vector<int>(nums.begin(), nums.begin()+(n-k));
            for (int i = 0; i < n;i++) {
                if (i < k) {
                    nums[i] = nums[n-k+i];
                } else {
                    nums[i] = temp[i-k];
                }
            }
        } else {
            // 后面移到前面
            vector<int> temp = vector<int>(nums.begin()+(n-k), nums.end());
            for (int i = 0; i < n;i++) {
                if (n-1-i >= k) {
                    nums[n-1-i] = nums[n-1-i-k];
                } else {
                    nums[n-1-i] = temp[n-1-i];
                }
            }
        }
    }


    void Leetcode::main_189() {
        vector<int> vec1{1,2,3,4,5,6,7};
        rotate(vec1, 2);
        printVector(vec1);

        vector<int> vec2{-1,-100,3,99};
        rotate(vec2, 2);
        printVector(vec2);
    }
}
