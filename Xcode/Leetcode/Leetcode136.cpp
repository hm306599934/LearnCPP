//
//  Leetcode136.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/23.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // map
    int singleNumber1(vector<int>& nums) {
        map<int, bool> m;
        for (int i = 0; i < nums.size();i++) {
            if (m[nums[i]]) {
                m.erase(nums[i]);
            } else {
                m[nums[i]] = true;
            }
        }

        return (int)(m.begin()->first);
    }

    // set
    int singleNumber2(vector<int>& nums) {
        set<int> s;
        int num = 0;
        for (int i = 0; i < nums.size();i++) {
            num -= nums[i];
            s.insert(nums[i]);
        }
        set<int>::iterator iter = s.begin();
        while (iter != s.end()) {
            num += *iter * 2;
            iter++;
        }

        return num;
    }

    // 异或
    int singleNumber(vector<int>& nums) {
        int res = 0;
        cout << endl;
        for (int num : nums) {
            res ^= num;
            cout  << num << " | " << res << endl ;
        }

        return res;
    }

    // 给定一个非空数组, 数组中除了一个数字出现1次, 其他数字都出现2次.
    // 找出出现一次的数字.
    void Leetcode::main_136() {
        vector<int> a{2,2,1};
        //cout << 1 << " | " << singleNumber(a) << endl;
        vector<int> b{4,1,2,1,2};
        cout << 4 << " | " << singleNumber(b) << endl;
    }
}
