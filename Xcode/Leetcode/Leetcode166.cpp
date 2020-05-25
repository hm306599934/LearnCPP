//
//  Leetcode166.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/13.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

     string fractionToDecimal(int numerator, int denominator) {
         string res;
         // 整数部分
         bool isSameSimple = true;
         if ((numerator < 0 && denominator > 0) ||
             (numerator > 0 && denominator < 0)) {
             isSameSimple = false;
             res += "-";
         }
         int64_t a = abs((int64_t)numerator / (int64_t)denominator);
         res += to_string(a);
         if (isSameSimple) {
             numerator -= a * denominator;
         }else{
             numerator += a * denominator;
         }
         // 小数部分
         string leftStr;
         string leftLoop;
         unordered_map<int64_t, int> map;
         while(numerator != 0) {
             int64_t newNum = (int64_t)numerator * 10;
             numerator = newNum % denominator;
             if (map.count(newNum) > 0) {
                leftLoop = leftStr.substr(map[newNum]);
                leftStr = leftStr.substr(0, map[newNum]);
                 break;
             }
             map[newNum] = (int)leftStr.size();
             leftStr += to_string(abs(newNum / denominator));
         }

         if (leftStr.size() > 0 || leftLoop.size() > 0) {
             res += "." + leftStr;
             if(leftLoop.size() > 0) {
                 res += "(" + leftLoop + ")" ;
             }
         }

         return res;
     }

    void Leetcode::main_166() {

        cout << "-0.58(3) : " << fractionToDecimal(7, -12) << endl;
        cout << "-6.25 : " << fractionToDecimal(-50, 8) << endl;
        cout << "2 : " << fractionToDecimal(2, 1) << endl;

        cout << "-0.58(3) : " << fractionToDecimal(-1, -2147483648) << endl;
        cout << "0.5 : " << fractionToDecimal(1, 2) << endl;
        cout << "0.125 : " << fractionToDecimal(1, 8) << endl;
        cout << "0.(6) : " << fractionToDecimal(2, 3) << endl;
        cout << "0.(3) : " << fractionToDecimal(1, 3) << endl;
        cout << "0.(142857) : " << fractionToDecimal(1, 7) << endl;
        cout << "0.(5) : " << fractionToDecimal(5, 9) << endl;
        cout << "8.8(3) : " << fractionToDecimal(53, 6) << endl;
        cout << "0.(012) : " << fractionToDecimal(4, 333) << endl;
    }
}
