//
//  Leetcode198.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/18.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // dp
    int rob(vector<int>& nums) {
        if (nums.empty())   return 0;
        int n = (int)nums.size();
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];

        for (int i = 2; i <= nums.size(); i++) {
            dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
        }
        return dp[n];
    }

    void Leetcode::main_198() {
        vector<int> v1{1,2,3,1};
        cout << "4 : " << rob(v1) <<endl;
        vector<int> v2{2,7,9,3,1};
        cout << "12 : " << rob(v2) <<endl;
        vector<int> v3{3,5};
        cout << "12 : " << rob(v3) <<endl;
    }
}
