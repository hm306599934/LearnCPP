//
//  Leetcode387.cpp
//  Xcode
//
//  Created by Jimmy on 2020/1/6.
//  Copyright © 2020 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    int firstUniqChar(string s) {

        vector<int> vec(26,0);
        for (char a : s) {
            vec[a-'a']++;
        }
        for (int i = 0;i < s.size();i++) {
            if (vec[s[i]-'a'] == 1) {
                return i;
            }
        }
        return -1;
    }

    void Leetcode::main_387() {
        cout << "leetcode : " << firstUniqChar("leetcode") << endl;
        cout << "loveleetcode : " << firstUniqChar("loveleetcode") << endl;
    }
}
