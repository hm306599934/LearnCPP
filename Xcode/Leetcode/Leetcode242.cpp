//
//  Leetcode242.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/9.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    bool isAnagram1(string s, string t) {
        vector<int> vec1(26, 0);
        vector<int> vec2(26, 0);
        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            vec1[s[i]-'a']++;
            vec2[t[i]-'a']++;
        }

        for (int i = 0;i < 26;i++) {
            if (vec1[i] != vec2[i]) {
                return false;
            }
        }
        return true;
    }

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> vec1(s.size(),0);
        vector<int> vec2(t.size(),0);
        unordered_map<char, int> m_map;

        for (int i = 0; i < s.size(); i++) {
            if (m_map.count(s[i]) == 0) {
                m_map[s[i]] = (int)m_map.size();
            }
            vec1[m_map[s[i]]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (m_map.count(t[i]) == 0) {
                return false;
            }
            vec2[m_map[t[i]]]++;
        }
        for (int i = 0;i < m_map.size();i++) {
            if (vec1[i] != vec2[i]) {
                return false;
            }
        }

        return true;
    }

    // 颠倒顺序
    void Leetcode::main_242() {
        cout << "false: " << isAnagram("a", "a") << endl;
        cout << "true: " << isAnagram("anagram", "nagaram") << endl;
        cout << "false: " << isAnagram("rat", "car") << endl;

    }
}
