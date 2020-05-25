//
//  Leetcode41.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/17.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // dp
    int firstMissingPositive2(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> dp(n+1, INT_MAX);
        for(int i = 1; i <= n; i++) {
            int ii = i -1;
            for (int j = 0;j < i;j++) {
                dp[i] = min(dp[j], nums[ii]);
            }
        }

        return dp[n] -1;
    }

    // stack
    int firstMissingPositive3(vector<int>& nums) {
        int n = (int)nums.size();
        stack<int> s;

        for(int i = 0; i < n; i++) {
            int a = nums[i];
            if (a <= 0) {
                continue;
            }
            if (s.empty()) {
                s.push(a);
            } else {

            }

        }

        return s.top() + 1;
    }

    // map
    int firstMissingPositive(vector<int>& nums) {
        map<int, bool> dic;

        for(int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            if (a <= 0) continue;
            dic[a] = true;
        }

        int res = 0;
        while (dic[++res]) {}
        return res;
    }

    // 题目: 给一个数组, 求数组中遗漏的最小正整数
    // 要求: 时间复杂度O(n), 空间复杂度是常数
    // 分析: 感觉可以使用dp, 貌似stack也可以
    // dp: 时间复杂度达不到要求
    // stack:也不行
    // map:
    void Leetcode::main_41() {
        vector<int> a1{7,3,5,2,6,4};
        vector<int> a2{1,2,0};
        vector<int> a3{3,4,-1,1};
        vector<int> a4{7,8,9,11,12};
        vector<int> a5{1,1};
        vector<int> a6{2,1};
        cout << firstMissingPositive(a1)<<endl;
        cout << firstMissingPositive(a2)<<endl;
        cout << firstMissingPositive(a3)<<endl;
        cout << firstMissingPositive(a4)<<endl;
        cout << firstMissingPositive(a5)<<endl;
        cout << firstMissingPositive(a6)<<endl;

    }
}
