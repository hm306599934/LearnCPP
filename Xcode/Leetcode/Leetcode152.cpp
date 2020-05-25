//
//  Leetcode152.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/8.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // 循环, 双指针
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            res = max(res, temp);
            for (int j = i+1;j < nums.size();j++) {
                temp *= nums[j];
                if (temp > res) {
                    res = temp;
                }
            }
            res = max(res, temp);
        }
        return res;
    }


    //dp
    int maxProduct3(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = (int)nums.size();

        vector<int> maxP(n, 0), minP(n, 0);
        maxP[0] = nums[0];
        minP[0] = nums[0];
        int maxProduct = nums[0];

        for(int i = 1; i < n; i++){
            maxP[i] = max(nums[i], max(maxP[i-1] * nums[i], minP[i-1] * nums[i]));
            minP[i] = min(nums[i], min(minP[i-1] * nums[i], maxP[i-1] * nums[i]));
            maxProduct = max(maxProduct, maxP[i]);
        }

        return maxProduct;
     }

    // 求一个连续的子数组的乘积, 输出最大的乘积结果
    void Leetcode::main_152() {
        vector<int> vec1{2,3,-2,4};
        cout << maxProduct(vec1) << endl;
        vector<int> vec2{-2,0,-1};
        cout << maxProduct(vec2) << endl;
        vector<int> vec3{-3,0,1,-2};
        cout << maxProduct(vec3) << endl;


    }
}
