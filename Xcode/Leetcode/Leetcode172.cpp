//
//  Leetcode172.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/12.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    int trailingZeroes(int n) {
        int res = 0;
        long num = 5;
        vector<int> dp;
        while (num <= n) {
            int left = n / num;
            num *= 5;
            res += left;
        }

        return res;
    }

    int64_t trailingN(int64_t n) {
        int64_t res = 1;
        if (n == 1) {
            return res;
        }

        return n * trailingN(n-1);
    }

    void Leetcode::main_172() {

        //cout << "0: " << trailingZeroes(3)<<endl;
        //cout << "1: " << trailingZeroes(5)<<endl;
        //cout << "3: " << trailingZeroes(15)<<endl;
        cout << trailingN(25) << " : " << trailingZeroes(30)<<endl;

    }
}

