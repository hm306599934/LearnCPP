//
//  Leetcode190.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/19.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        int i = 0;
        while(n > 0) {
            int x = 1<<i++;
            if ((n & x) == x) {
                n -= x;
                res += 1<<(32-i);
            }
        }

        return res;
    }

    void Leetcode::main_190() {
        cout << "964176192 : " << reverseBits(43261596) << endl;;
    }
}

