//
//  OJ_11_4.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/20.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <unordered_map>
#include <stdlib.h>
using namespace std;

namespace Jimmy {

int method(vector<int>& nums) {
    if (nums.empty())   return 0;
    int n = (int)nums.size();
    vector<int> dp(n+1, 0);
    dp[1] = nums[0];

    for (int i = 2; i <= nums.size(); i++) {
        dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
    }
    return dp[n];
}

void OJ::main_11_4()
{
    int n;
    cin >> n;
    vector<int> vec;
    while (n > 0) {
        int a;
        cin>>a;
        vec.push_back(a);
        n--;
    }
    cout << method(vec);
    Jimmy::printVector(vec);
}

}
