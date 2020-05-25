//
//  Leetcode131.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/28.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    bool isPalindrome(string &s, int start, int end) {
        while (start < end && s[start] == s[end]) {
            start++;
            end--;
        }
        return start >= end;
    }


    void paritionRecrution(string &s, int index, vector<string> &vec, vector<vector<string>> &res) {
        if (index == s.size() && !vec.empty()) {
            res.push_back(vec);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                vec.push_back(s.substr(index, i - index + 1));
                paritionRecrution(s, i + 1, vec, res);
                vec.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> cur;
        if(s.empty()) return result;
        paritionRecrution(s, 0, cur, result);
        return result;
    }

    void Leetcode::main_131() {
        vector<vector<string>> a1 = partition("aab");
        cout << a1.size() << endl;
    }
}
