//
//  Leetcode217.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/25.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    bool containsDuplicate2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size();i++) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
    }


    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;

        for(int num : nums) {
            if (map.count(num) > 0) {
                return true;
            }
            map[num] = num;
        }
        return false;
    }

    //  给定一个数组, 找到是否有重复数字
    void Leetcode::main_217() {
        vector<int> v1{1,1,1,3,3,4,3,2,4,2};
        cout << "true : " << containsDuplicate(v1) << endl;
    }
}
