//
//  OJ_11_3.cpp
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


int method3(vector<vector<int>>& vec) {
    if (vec.empty()) return 0;
    int n = (int)vec.size();
    int i = 0, j = 0;
    vector<vector<int>> dp(n, vector<int>(n,0));

    dp[n-1][n-1] = vec[n-1][n-1];

    for (i = n-2; i >= 0; i--){
        dp[i][n-1] = dp[i+1][n-1] + vec[i][n-1];
    }

    for (j = n-2; j >= 0; j--){
        dp[n-1][j] = dp[n-1][j+1] + vec[n-1][j];
    }

    for (i = n-2; i >= 0; i--){
        for (j = n-2; j >= 0; j--){
            dp[i][j] = vec[i][j] + min(dp[i+1][j], dp[i][j+1]);
        }
    }

    return dp[0][0];
}

void OJ::main_11_3()
{

    int n;
    cin >> n;

    vector<int> res;

    while (n > 0) {
        int m;
        cin >> m;
        vector<vector<int>> vec;
        int k = m;
        while (m > 0) {
            int count = k;
            vector<int> temp;
            while (count > 0) {
                int a;
                cin>>a;
                temp.push_back(a);
                count--;
            }
            vec.push_back(temp);
            m--;
        }
        res.push_back(method3(vec));
        n--;
    }

    for (int aa : res) {
        cout << aa << endl;
    }
}

}
