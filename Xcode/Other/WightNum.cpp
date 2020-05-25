//
//  Wight.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/15.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {


    int weightNum(vector<int> wights, vector<int> nums) {
        int m = (int)wights.size();


        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += wights[i] * nums[i];
        }

        set<int> s;
        s.insert(sum);
        for (int i = 0; i < wights.size(); i++) {
            set<int>::iterator iter = s.begin();
            while(iter != s.end()) {
                for (int k = 1; k <= nums[i] && *iter - k * wights[i] > 0; k++)
                    s.insert(*iter - k * wights[i]);
                iter++;
            }
        }

        return (int)s.size() + 1;

    }

    void Other::main_weightNum() {

        cout << weightNum(vector<int>{1,2, 3}, vector<int>{2, 1, 1}) <<endl;
    }
}
