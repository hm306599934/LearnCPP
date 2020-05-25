//
//  Leetcode300.cpp
//  Xcode
//
//  Created by Jimmy on 2020/1/8.
//  Copyright © 2020 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    int lengthOfLISHelper(vector<int>& nums, int flag, int pos) {
        if (pos >= nums.size()) return 0;
        int count = 0;
        if (nums[pos] > flag) {
            count = lengthOfLISHelper(nums, nums[pos], pos+1) + 1;
        }
        int nextCount = lengthOfLISHelper(nums, flag, pos+1);
        return max(nextCount, count);
    }

    int lengthOfLIS(vector<int>& nums) {
        return lengthOfLISHelper(nums, INT_MIN, 0);
    }

    // DP
    int lengthOfLIS2(vector<int>& nums) {
        if (nums.empty()) return 0;
        // 记录nums[i]的最大子序列个数
        vector<int> dp(nums.size());
        int count = 1;
        dp[0] = 1;

        for (int i = 1; i < nums.size(); i++) {
            int maxCount = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    maxCount = max(maxCount, dp[j]);
                }
            }
            dp[i] = maxCount + 1;
            count = max(count, dp[i]);
        }
        return count;
    }


    // LIS: Longest increasing Subsequence
    void Leetcode::main_300() {

        vector<int> v3{4,10,4,3,8,9};
        cout << "3 : " << lengthOfLIS(v3)<<endl;

        vector<int> v1{10, 9, 2, 5, 3, 7, 101, 18};
        cout << "4 : " << lengthOfLIS(v1) << endl;

        vector<int> v2{10};
        cout << "1 : " << lengthOfLIS(v2)<<endl;
    }
}
