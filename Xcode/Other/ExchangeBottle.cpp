//
//  ExchangeBottle.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/15.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {
    // 换瓶子问题, 每3个瓶子换一瓶汽水, 最后只剩两个瓶子可以借一瓶汽水喝完再还3个瓶子.
    // 内循环, 通过不确定次数循环, 每次降低循环参数
    int bottles(int n) {
        int count = 0;
        while (n > 2) {
            int left = n / 3 + n % 3;
            count += n / 3;
            n = left;
        }

        if (n == 2) {
            count += 1;
        }
        return count;
    }

    void Other::main_exchangeBottle() {
        cout << bottles(82) << endl;
    }
}
