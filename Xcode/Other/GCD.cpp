//
//  GCD.cpp
//  Xcode
//
//  Created by Jimmy on 2020/1/20.
//  Copyright © 2020 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

//    static int gcd2(int a, int b) {
//        int x = min(a,b);
//        for (; x > 1; x--) {
//            if (a % x == 0 && b % x == 0) {
//                return x;
//            }
//        }
//        return x;
//    }

    // 辗转相除法 GCD(a%b) == GCD(b%r), r = a % b
//    static int gcd(int a, int b) {
//        if (a < b) return gcd(b, a);
//        int x = a % b;
//        if (x == 0) {
//            return b;
//        } else {
//            return gcd(b, x);
//        }
//    }

    // 极简版
//    static int gcd(int a, int b) {
//        return (b == 0) ? a : gcd(b,a%b);
//    }

    // 循环版本
    static int gcd(int a, int b) {
        while (b > 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    // greatest common divisor
    void Other::main_gcd() {
        cout << "5 : "<<gcd(10, 15)<<endl;
        cout << "5 : "<<gcd(15, 10)<<endl;
        cout << "1 : "<<gcd(3, 5)<<endl;
        cout << "5 : "<<gcd(5, 15)<<endl;
        cout << "6 : "<<gcd(18, 24)<<endl;

    }
}
