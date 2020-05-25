//
//  Leetcode162.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/8.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    int findPeakElement2(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1) {
            return 0;
        } else if (nums[0] > nums[1]) {
            return 0;
        } else if (nums[n-1] > nums[n-2]) {
            return n-1;
        }

        for(int i = 1;i < nums.size()-1;i++) {
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                return i;
            }
        }
        return 0;
    }

    int findPeakElement(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1) {
            return 0;
        } else if (nums[0] > nums[1]) {
            return 0;
        } else if (nums[n-1] > nums[n-2]) {
            return n-1;
        }

        for(int i = 1;i < nums.size()-1;) {
            if (nums[i-1] > nums[i]) {
                i += 2;
            } else if (nums[i+1] > nums[i]) {
                i +=1;
            } else {
                return i;
            }
        }
        return 0;
    }

    void Leetcode::main_162() {
        vector<int> vec1{1,2,3,1};
        cout << findPeakElement(vec1) << endl;
        vector<int> vec2{1,2,1,3,5,6,4};
        cout << findPeakElement(vec2) << endl;;

    }
}
