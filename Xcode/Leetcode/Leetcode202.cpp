//
//  Leetcode202.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/25.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    bool isHappy(int n) {
        unordered_set<int> m_set;
        int temp = n;
        int sum = 0;
        while (temp != 1) {
            while (temp != 0) {
                int x = temp % 10;
                sum += x * x;
                temp = temp / 10;
            }
            if (sum == 1){
                break;
            } else if (m_set.count(sum) > 0) {
                return false;
            } else {
                temp = sum;
                m_set.insert(sum);
                sum = 0;
            }
        }

        return true;
    }

    // 判断一个数字是否快乐
    // 把一个数字转换为各位上的单个数子平方和, 不停循环知道最后等于1或者无限循环
    // 如果最后等于1即为happy
    void Leetcode::main_202() {
        cout << "true : " << isHappy(19)<<endl;
        cout << "true : " << isHappy(16)<<endl;
        cout << "true : " << isHappy(19)<<endl;


    }
}
