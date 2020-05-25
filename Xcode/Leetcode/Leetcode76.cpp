//
//  Leetcode76.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/10.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"
#include "Helper.hpp"
using namespace std;

namespace Jimmy {

//    string minWindow(string s, string t) {
//        int left = 0, right = 0;
//        int min_length = 0, pos = 0;
//        int sum = (int)t.size();
//
//        map<char, int> map_char;
//        for (int i = 0; i < t.size(); i++) {
//            map_char[t[i]]++;
//        }
//
//        while (right < s.size()) {
//            map_char[s[right]]--;
//            if (map_char[s[right]] >= 0) sum--;
//
//            while(sum == 0 && left <= right) {
//                if (min_length == 0 || min_length > right - left + 1) {
//                    min_length = right - left + 1;
//                    pos = left;
//                }
//                if (++map_char[s[left++]] > 0) {
//                    sum++;
//                }
//            }
//
//            right++;
//        }
//        if (min_length == 0) return "";
//        return s.substr(pos, min_length);
//    }

    string minWindow(string s, string t) {
        map<char,int> tMap;
        for(int i = 0;i < t.size();i++){
            tMap[t[i]]++;
        }

        int l = 0, r = 0;
        int pos = 0, len = 0;
        int count = (int)t.size();

        while (r < s.size()) {
            tMap[s[r]]--;
            if(tMap[s[r]] >= 0) count--;

            while (count == 0 && l <= r) {
                if (len == 0 || len > r - l + 1) {
                    len = r -l + 1;
                    pos = l;
                }
                if (++tMap[s[l++]] > 0) {
                    count++;
                }
            }
            r++;
        }

        return s.substr(pos, len);
    }

    void Leetcode::main_76() {
        cout << minWindow("cabwefgewcwaefgcf","cae") <<endl;
    }
}

