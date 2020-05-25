//
//  Leetcode215.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/20.
//  Copyright © 2019 Airactart. All rights reserved.
//
//  找到第k大的数

#include "Header.hpp"

namespace Jimmy {

    void findKthLargestSort(vector<int>& nums, int l, int r) {
       if (l < r) {
            int i = l, j = r, x = nums[l];
            while (i < j) {
                while (i < j && x > nums[j]) j--;
                if (i < j) nums[i++] = nums[j];
                while (i < j && nums[i] > x) i++;
                if (i < j) nums[j--] = nums[i];
            }
            nums[i] = x;
            findKthLargestSort(nums, l, i-1);
            findKthLargestSort(nums, i+1, r);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty()) return -1;
        findKthLargestSort(nums, 0, (int)nums.size()-1);
        return nums[k-1];
    }

    void Leetcode::main_215() {
        //vector<int> v2{3,2,3,1,2,4,5,5,6};
        //cout <<"4 : " << findKthLargest(v2, 4) << endl;

        vector<int> v1{3,2,1,5,6,4};
        cout <<"5 : " << findKthLargest(v1, 2) << endl;
    }
}
