//
//  Leetcode344.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/23.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            char temp = s[s.size()-1-i];
            s[s.size()-1-i] = s[i];
            s[i] = temp;
        }
    }

    void Leetcode::main_344() {
        vector<char> str{'h','e','l','l','o'};
        reverseString(str);
        printCharVector(str);
    }
}
