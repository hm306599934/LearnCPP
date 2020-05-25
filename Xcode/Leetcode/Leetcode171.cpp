//
//  Leetcode171.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/12.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    int titleToNumber(string s) {
        int res = 0;
        for(char c : s) {
            res *= 26;
            res += c - 'A' + 1;
        }
        return res;
    }

    void Leetcode::main_171() {
        cout << "701: " << titleToNumber("");
    }
}
