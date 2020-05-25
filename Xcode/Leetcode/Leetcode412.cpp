//
//  Leetcode412.cpp
//  Xcode
//
//  Created by Jimmy on 2020/1/6.
//  Copyright © 2020 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);

        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                res[i-1] = "FizzBuzz";
            } else if (i % 3 == 0) {
                res[i-1] = "Fizz";
            } else if (i % 5 == 0) {
                res[i-1] = "Buzz";
            } else {
                res[i-1] = to_string(i);
            }
        }
        return res;
    }
    void Leetcode::main_412() {
        vector<string> res = fizzBuzz(15);
        printVector(res);

    }
}
