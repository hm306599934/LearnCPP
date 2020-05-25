//
//  Leetcode287.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/17.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    int findDuplicate2(vector<int>& nums) {

        int res = 0;
        for (int i = 0; i < nums.size()-1;i++) {
            res = nums[i];
            for (int j = i+1; j < nums.size();j++) {
                if (res == nums[j]) {
                    return res;
                }
            }
        }
        return 0;
    }

    int findDuplicate(vector<int>& nums) {
        int low = 1, high = (int)nums.size()-1;
        while (low < high) {
            int mid = (low + high) / 2;
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) count++;
            }
            if (count > mid) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        return high;
    }
    // 找出数组中重复的数字，有n+1个数字为1~n的数字,只有一个重复数字
    // 空间复杂度为O(1)，不能移动数组
    void Leetcode::main_287() {

        vector<int> v3{2,2,2};
        cout << "2 : " << findDuplicate(v3) << endl;

        vector<int> v1{1,3,4,2,2};
        cout << "2 : " << findDuplicate(v1) << endl;

        vector<int> v2{3,1,3,4,2};
        cout << "3 : " << findDuplicate(v2) << endl;
    }
}
