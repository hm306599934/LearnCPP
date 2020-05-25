//
//  Leetcode125.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/28.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {
    // 双指针, 一个在左边, 一个在右边
    bool isPalindrome(string s) {
        int n = (int)s.size();
        int l = 0, r = n - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            while (l < r && !isalnum(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                break;
            }
            l++;
            r--;
        }
        return l >= r;
    }

    // 判断字符串是否回文, 不考虑标点符号特殊字符
    void Leetcode::main_125() {
        cout << "true | " << isPalindrome("A man, a plan, a canal: Panama") << endl;
        cout << "false | " << isPalindrome("race a car") << endl;
        cout << "true | " << isPalindrome("aabaa") << endl;
        cout << "true | " << isPalindrome(".,") << endl;
    }
}
