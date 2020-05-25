//
//  Leetcode238.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/4.
//  Copyright © 2019 Airactart. All rights reserved.
//
//  给定一个数组，输出一个数组，数组元素是除自己以外所有元素的乘积。

#include "Header.hpp"

namespace Jimmy {

    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeroCount = 0;
        int zeroProduct = 1;
        for (int x : nums) {
            product *= x;
            if (x == 0) {
                zeroCount++;
                continue;
            }
            zeroProduct *= x;
        }

        if (zeroCount > 1) {
            return vector<int>(nums.size(),0);
        }

        vector<int> res;
        for (int x : nums) {
            if (x == 0) {
                res.push_back(zeroProduct);
            } else {
                res.push_back(product / x);
            }
        }
        return res;
    }

    void Leetcode::main_238() {
        vector<int> v1{1,0};
        printVector(productExceptSelf(v1));
        vector<int> v{1,2,3,4};
        printVector(productExceptSelf(v));
    }
}
