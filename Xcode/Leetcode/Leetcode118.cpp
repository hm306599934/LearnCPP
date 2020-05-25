//
//  Leetcode118.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/25.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {



    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        while (res.size() < numRows) {
            int n = (int)res.size();
            vector<int> vec(n+1, 1);
            cout << " n " << n  << " " << n - 1 << endl;
            for (int i = 1; i < n; i++) {
                vec[i] = res[n-1][i-1]+res[n-1][i];
            }
            res.push_back(vec);
        }
        return res;
    }

    void Leetcode::main_118() {
        vector<vector<int>> res = generate(5);
        cout << res.size() << endl;
    }
}
