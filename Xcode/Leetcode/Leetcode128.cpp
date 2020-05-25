//
//  Leetcode128.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/13.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {
    // 排序
    int longestConsecutive2(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());

        int res = 1;
        int count = 1;
        for(int i = 1; i < nums.size();i++) {
            if (nums[i] == nums[i-1]) {
                continue;
            } else if (nums[i] == nums[i-1]+1) {
                count++;
                if (count > res) {
                    res = count;
                }
            } else {
                count = 1;
            }
        }
        return res;
    }

    // hash
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        set<int> s(nums.begin(), nums.end());
        
        int res = 1;
        int count = 1;
        set<int>::iterator first = s.begin();
        set<int>::iterator last = first++;
        while (last != s.end()) {
            if (*first+1 == *last) {
                count++;
                if (count > res) {
                    res = count;
                }
            } else {
                count = 1;
            }
            first = last;
            last++;
        }

        return res;
    }

    // 给定一个字符串, 找出最长的连续数字长度
    void Leetcode::main_128() {
        vector<int> vec3{0};
        cout << " 1 : " << longestConsecutive(vec3) << endl;
        vector<int> vec2{1,2,0,1};
        cout << " 3 : " << longestConsecutive(vec2) << endl;
        vector<int> vec1{100,4,200,1,3,2};
        cout << " 4 : " << longestConsecutive(vec1) << endl;

    }
}
