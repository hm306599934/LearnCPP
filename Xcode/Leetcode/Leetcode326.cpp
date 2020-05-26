//
//  Leetcode326.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/18.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    bool isPowerOfThree2(int n) {
        // 3的19次方
        return n > 0 && 1162261467 % n == 0;
    }

    bool isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }


    // 判断是否是3的n次方，不使用循环和递归

    void Leetcode::main_326() {

        cout << "false : "<< isPowerOfThree(4782968) <<endl;
        cout << "true : "<< isPowerOfThree(27) <<endl;
        cout << "false : "<< isPowerOfThree(45) << endl;
        cout << (1 << 2) << endl;
        cout << (1 << 3) << endl;
        cout << (3 << 0) << endl;
        cout << (3 << 0) << endl;
    }
}
