//
//  Leetcode454.cpp
//  Xcode
//
//  Created by Jimmy on 2020/1/6.
//  Copyright © 2020 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> ab;
        for (int a : A) {
            for (int b : B) {
                ab[a+b]++;
            }
        }

        for (int c : C) {
            for (int d : D) {
                if (ab.count(-c-d) > 0) {
                    res += ab[-c-d];
                }
            }
        }
        return res;
    }

    void Leetcode::main_454() {
        vector<int> a{ 1, 2};
        vector<int> b{-2,-1};
        vector<int> c{-1, 2};
        vector<int> d{ 0, 2};
        cout << fourSumCount(a, b, c, d) << endl;
    }
}
