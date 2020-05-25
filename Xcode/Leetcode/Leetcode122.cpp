//
//  Leetcode122.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/23.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // 解析: 取一个值, 然后求递增最大值
    // 双指针, 一次移动一个指针
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        if (n <= 1) return 0;

        int res = 0, l = 0;

        for(int i = 1;i < n; i++) {
            if (prices[i] <= prices[l]) {
                l = i;
            } else {
                int tmpR = prices[i];
                for(int j = i + 1;j < n; j++) {
                    if (prices[j] >= tmpR) {
                        i = j;
                        tmpR = prices[j];
                    } else {
                        break;
                    }
                }
                res += prices[i] - prices[l];
                l = i + 1;
            }
        }
        return res;
    }

    // 股票获取最大利润, 可以进行多次交易
    // 给定一个数组, 索引表示天, 值表示价格
    void Leetcode::main_122() {
        vector<int> a{7,1,5,3,6,4};
        cout << maxProfit(a) << " | " << 7 <<endl;
        vector<int> b{1,2,3,4,5};
        cout << maxProfit(b) << " | " << 4 <<endl;
        vector<int> c{7,6,4,3,1};
        cout << maxProfit(c) << " | " << 0 <<endl;
        vector<int> d{1,2};
        cout << maxProfit(d) << " | " << 1 <<endl;
    }
}
