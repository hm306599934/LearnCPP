//
//  Leetcode139.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/29.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    bool isMatch(string s, int &start, vector<string>& words) {

        for (int i = 0; i < words.size(); i++) {
            string ss = words[i];
            bool isMatch = true;
            for (int j = 0; j < ss.size();j++) {
                if (s[start + j] != ss[j]) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                start += ss.size();
                return true;
            }
        }
        return false;
    }

    bool workBreakRecrution(string &s, int index, vector<string>& words, int wordIndex) {
        cout << index << endl;
        if (s.size() == index) {
            return true;
        }
        if (wordIndex >= words.size()) {
            return false;
        }

        string ss = words[wordIndex];
        string substring = s.substr(index, ss.size());
        if (ss == substring) {
            workBreakRecrution(s, index + (int)ss.size(), words, 0);
            workBreakRecrution(s, index, words, wordIndex+1);
        } else {
            workBreakRecrution(s, index, words, wordIndex+1);
        }

        return wordIndex < words.size();
    }

    // 递归
    bool wordBreak3(string s, vector<string>& wordDict) {
        int index = 0;
        int dictIndex = 0;

        cout << "| "<< workBreakRecrution(s, index, wordDict, dictIndex) << endl;

        return false;
    }

    bool wordBreak2(string s, vector<string>& w) {
           vector<bool> dp (s.length() + 1);
           dp[0] = true;

           for (int i=1; i<=s.length(); i++) {
               int index = i - 1;

               for (int j=0; j<w.size(); j++) {
                   string st = s.substr(index, w[j].length());
                   if (st == w[j]) {
                       if (!dp[index + st.length()]) {
                           dp[index + st.length()] = dp[index];
                       }
                   }
               }
           }

           return dp[s.length()];
       }

    // dp
    bool wordBreak5(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 0;i < s.size();i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                string word = wordDict[j];
                string ss = s.substr(i, word.size());
                if (ss == word) {
                    if (!dp[i + word.size()]) {
                        dp[i + word.size()] = dp[i];
                    }
                }
            }
        }

        return dp[s.size()];
    }

    // dfs
    bool wordBreak6(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);

        return dp[s.size()];
    }

    bool wordBreakRecrution(string &s, int index, vector<string>& words, vector<int> &flags) {
        if (index == s.size()) {
            return true;
        }

        for (int i = 0; i < words.size();i++) {
            string word = words[i];
            int len = (int)word.size();
            if (s.substr(index, len) == word) {
                if (flags[index] != -1) {
                    return flags[index];
                } else if (wordBreakRecrution(s, index + len, words, flags)) {
                    flags[index] = true;
                    return true;
                }
            }
        }
        flags[index] = false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict)
    {
        vector<int> flags(s.size() + 1, -1);
        return wordBreakRecrution(s, 0 , wordDict, flags);
    }

    // 给定一个字符串和一个字符串数组
    // 使用数组中的字符拼接给定的字符串, 数组的字符可以重复使用
    // dp
    // dfs
    // 递归
    // 循环
    void Leetcode::main_139() {
        vector<string> vec1{"leet", "code"};
        cout << wordBreak("leetcode", vec1) << endl;

        vector<string> vec2{"apple", "pen"};
        cout << wordBreak("applepenapple", vec2) << endl;

        vector<string> vec3{"cats", "dog", "sand", "and", "cat"};
        cout << wordBreak("catsandog", vec3) << endl;

        vector<string> vec4{"ndog","catsa", "dog", "sand", "and", "cat"};
        cout << wordBreak("catsandog", vec4) << endl;

        vector<string> vec5{"car","ca", "rs"};
        cout << wordBreak("cars", vec5) << endl;
    }
}
