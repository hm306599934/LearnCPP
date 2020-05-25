//
//  Leetcode169.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/13.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    int majorityElement2(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_map<int, int> map;
        int max = 0;
        int res = nums[0];
        for(int a : nums) {
            if (map.count(a) == 0) {
                map[a] = 1 ;
            } else {
                map[a] += 1;
            }
            if (map[a] > max) {
                max = map[a];
                res = a;
            }
        }
        return res;
    }

    int majorityElement3(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }

    int majorityElement(vector<int>& nums) {
        if (nums.empty()) return 0;
        for(int i = 0, j = 1; j < nums.size();) {
            while (nums[i] == INT_MIN) {
                i++;
            }
            if (nums[i] != nums[j]) {
                nums[i++] = INT_MIN;
                nums[j++] = INT_MIN;
            }else {
                j++;
            }
        }
        for(int a : nums) {
            if (a != INT_MIN) {
                return a;
            }
        }
        return nums[0];
    }

    void Leetcode::main_169() {
        vector<int> vec1{1,2,1,4,1,6,1};
        cout << "0 : " << majorityElement(vec1);
        vector<int> vec2{2,2,1,1,1,2,2};
        cout << "2 : " << majorityElement(vec2);
    }
}
