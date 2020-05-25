//
//  Leetcode191.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/18.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    int hammingWeight(uint32_t n) {
        int res = 0;
        int i = 0;
        while (n > 0) {
            int x = 1 << i++;
            if ((n & x) == x) {
                n -= x;
                res++;
            }
        }
        return res;
    }

    void Leetcode::main_191() {
        cout << "" << hammingWeight(11)<<endl;
    }
}
