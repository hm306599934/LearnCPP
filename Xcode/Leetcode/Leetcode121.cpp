//
//  Leetcode121.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/23.
//  Copyright © 2019 Airactart. All rights reserved.
//


#include "Header.hpp"

namespace Jimmy {
namespace Leetcode121 {
    // 解析: 循环 O(n²)
    int maxProfit1(vector<int>& prices) {
        int n = (int)prices.size();
        int res = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                res = max(prices[i] - prices[j], res);
            }
        }

        return res;
    }

    // 解析: min
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        if (n == 0) return 0;

        int res = 0, minP = prices[0];

        for (int i = 1; i < n; i++) {
            int tmp = prices[i];
            res = max(tmp - minP, res);

            if (tmp < minP) {
                minP = tmp;
            }
        }

        return res;
    }
}
using namespace Leetcode121;

    // 股票获取最大利润, 最多只能一次交易
    // 给定一个数组, 索引表示天, 值表示价格
    void Leetcode::main_121() {
        vector<int> a{7,1,5,3,6,4};
        cout << maxProfit(a) << " | " << 5 <<endl;
        vector<int> b{7,6,4,3,1};
        cout << maxProfit(b) << " | " << 0 <<endl;
    }
}
