//
//  Leetcode279.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/11.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1;i <= n; i++) {
            int a = sqrt(i);
            for (int j = 1; j <= a; j++) {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }

    // 找出用完美数组成n的最小个数
    // 完美数：1，4，9，16...
    // 12 = 4 + 4 + 4, 13 = 4 + 9
    void Leetcode::main_279() {
        //cout << "3 : " << numSquares(12) << endl;
        //cout << "2 : " << numSquares(13) << endl;
        cout << "3 : " << numSquares(48) << endl;
    }
}
