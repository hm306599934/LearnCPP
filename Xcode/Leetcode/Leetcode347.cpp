//
//  Leetcode347.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/31.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty()) return res;
        unordered_map<int, int> mp;
        for (auto& e : nums) mp[e]++;

        vector<pair<int, int>> count(mp.begin(), mp.end());
        sort(count.begin(), count.end(), [](pair<int, int> a, pair<int, int> b){return a.second > b.second;});
        for (int i = 0; i < k; i++) {
            res.push_back(count[i].first);
        }

        return res;
    }

    // 找出数组出现频率最高的k个数字
    void Leetcode::main_347() {
        vector<int> v1{1,1,1,2,2,3,3,3,3};
        printVector(topKFrequent(v1,2));
    }
}
