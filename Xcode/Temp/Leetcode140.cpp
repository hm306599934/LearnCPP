//
//  Leetcode140.cpp
//  Xcode
//
//  Created by Jimmy on 2020/1/15.
//  Copyright © 2020 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // 递归
//    void wordBreakHelper(string& str, vector<string>& words, int index, string temp,vector<string>& res) {
//        if (index == str.size()) {
//            if (!temp.empty()) {
//                temp = temp.substr(1);
//            }
//            res.push_back(temp);
//        } else if (index < str.size()) {
//            for (string word : words) {
//                int len = (int)word.size();
//                string subStr = str.substr(index,word.size());
//                if (word == subStr) {
//                    wordBreakHelper(str, words, index + len, temp+" "+word,res);
//                }
//            }
//        }
//    }
//
//    vector<string> wordBreak2(string s, vector<string>& words) {
//        vector<string> res;
//        wordBreakHelper(s, words, 0, "", res);
//        return res;
//    }


    // 循环

    void wordBreakDFS(string& s, const vector<unordered_set<int>>& vec, int i, vector<string>& res) {
        if (i < s.size()) {
            s.insert(i, 1, ' ');
        }
        for (int next : vec[i]) {
            if (next == 0) {
                res.push_back(s);
            }else {
                wordBreakDFS(s,vec,next,res);
            }
        }

        if (i < s.size()) {
            s.erase(i,1);
        }
    }

    vector<string> wordBreak(string s, vector<string>& words) {
        unordered_set<int> lens;
        unordered_set<string> dict;
           for (int i(0); i < words.size(); ++i) {
            lens.insert((int)words[i].size());
            dict.insert(words[i]);
        }

        int n = (int)s.size();
        vector<unordered_set<int>> dp(n+1, unordered_set<int>());
        for (int i = 1; i <= n; i++) {
            for (int l : lens) {
                if (l <= i) {
                    string word = s.substr(i-l,l);
                    if (dict.count(word)) {
                        if (l == i || !dp[i-l].empty()) {
                            dp[i].insert(i-l);
                        }
                   }
               }
            }
        }
        vector<string> rst;
        wordBreakDFS(s, dp, n, rst);
        return rst;
    }

    // 得定一个句子和一组单词, 用单词组成句子
    void Leetcode::main_140() {

//        vector<string> v4{"aaaa","aaa"};
//        vector<string> s4 = wordBreak("aaaaaaa", v4);
//        printVector(s4);
//
//        vector<string> v1{"cat", "cats", "and", "sand", "dog"};
//        vector<string> s1 = wordBreak("catsanddog", v1);
//        printVector(s1);

        vector<string> v2{"apple", "pen", "applepen", "pine", "pineapple"};
        vector<string> s2 = wordBreak("pineapplepenapple", v2);
        printVector(s2);

        vector<string> v3{"cats", "dog", "sand", "and", "cat"};
        vector<string> s3 = wordBreak("catsandog", v3);
        printVector(s3);

    }
}
