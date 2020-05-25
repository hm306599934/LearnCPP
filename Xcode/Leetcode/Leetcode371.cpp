//
//  Leetcode371.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/31.
//  Copyright © 2019 Jimmy. All rights reserved.
//
//  不用加法实现求和

#include "Header.hpp"

namespace Jimmy {


    int getSum(int a, int b) {
        int sum = a;
        unsigned int carry = 1;
        while (carry) {
            carry = sum & b;
            sum = sum ^ b;
            b = carry << 1;
        }
        return sum;
    }

    // 实现乘法
    int getMulti(int a, int b) {
        unsigned int carry = 1;
        int i = 0;
        int res = 0;
        while (carry <= b) {
            if (b & carry) {
                int temp = a << i;
                res = getSum(res, temp);
            }
            carry = carry << 1;
            i++;
        }

        return  res;
    }

    // 加法直接加
    // 减法取反加1
    void Leetcode::main_371() {
        //cout << (getSum(-1,1) == 0) << endl;
        //cout << (getSum(-1, 3) == 2) << endl;
        //cout << (getSum(-1, -3) == -4) << endl;
        //cout << (getSum(1, 3) == 4) << endl;
        //cout << getSum(-1, -3) << endl;
        //cout << getSum(1, -3) << endl;


        cout << (getMulti(3,10)) << endl;

        cout << (3 << 1) << endl;
    }
}
