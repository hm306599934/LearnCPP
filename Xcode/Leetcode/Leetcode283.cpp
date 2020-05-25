//
//  Leetcode283.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/11.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    void moveZeroes1(vector<int>& nums) {
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] != 0) {
                continue;
            }
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] != 0) {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    break;
                }
            }
        }
    }

    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2) return;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
            } else {
                nums[i-count] = nums[i];
            }
        }

        for (int i = (int)nums.size() - count; i < nums.size(); i++) {
            nums[i] = 0;
        }

    }

    void Leetcode::main_283() {
        vector<int> v1{0,1,0,3,12};
        moveZeroes(v1);
        printVector(v1);
    }
}
