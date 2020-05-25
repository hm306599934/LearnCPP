//
//  Leetcode322.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/18.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {
    //dp
    int coinChange2(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j]) {
                    if (dp[i] == -1 && dp[i-coins[j]] == -1) {
                        continue;
                    } else if (dp[i-coins[j]] == -1) {
                        continue;
                    }
                    if (dp[i] > 0) {
                        dp[i] = min(dp[i-coins[j]] + 1,dp[i]);
                    } else {
                        dp[i] = dp[i-coins[j]] + 1;
                    }

                }
            }
        }
        return dp[amount];
    }

    int coinChange(const vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 10000);
        dp[0] = 0;
        for (int i = 1; i < amount + 1; ++i)
        {
            for (int j = 0; j < coins.size(); ++j)
            {
                if (i >= coins[j] && dp[i - coins[j]] < 10000)
                {
                     dp[i] = min(dp[i - coins[j]], dp[i]);
                }
            }
            dp[i] += 1;
        }
        return dp[amount] >= 10000 ? -1 : dp[amount];
    }

    void Leetcode::main_322() {
        vector<int> v5{186,419,83,408};
        cout << "20 : "<<coinChange(v5, 6249)<<endl;
        vector<int> v4{2,5,10,1};
        cout << "4 : "<<coinChange(v4, 27)<<endl;
        vector<int> v1{1,2,5};
        cout << "3 : "<<coinChange(v1, 11)<<endl;
        cout << "3 : "<<coinChange(v1, 12)<<endl;
        cout << "3 : "<<coinChange(v1, 14)<<endl;
        cout << "3 : "<<coinChange(v1, 15)<<endl;
        vector<int> v3{1,2,3};
        cout << "3 : "<<coinChange(v3, 6)<<endl;
        vector<int> v2{2};
        cout << "-1 : "<<coinChange(v2, 3)<<endl;
    }
}

