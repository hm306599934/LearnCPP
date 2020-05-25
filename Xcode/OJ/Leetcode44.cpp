//
//  Leetcode44.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/21.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // 正则表达式匹配字符串
    // ?: 匹配任何单个字符
    // *: 匹配0或多个任意字符
    bool isMatch2(string s, string p) {
        int m = (int)p.size();
        int n = (int)s.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        // s,p都为空时为true
        dp[0][0] = true;

        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                int ii = i - 1;
                int jj = j - 1;
                if (p[ii] == '*' && i > 1) {
                    dp[i][j] = dp[ii-1][j];
                    if (jj >= 0 && (p[ii-1] == s[jj] || p[ii-1] == '?')) {
                        dp[i][j] = dp[i][j] || dp[i][jj];
                    }
                } else {
                    dp[i][j] = jj >= 0 && (p[ii] == s[jj] || p[ii] == '?') && dp[ii][jj];
                }
            }
        }

        return dp[m][n];
    }

//    bool isMatch(string s, string p) {
//        if (p.empty()) {
//            return s.empty();
//        }
//
//        if (s.empty()) {
//            for (char c : p) {
//                if (c != '*') {
//                    return false;
//                }
//            }
//            return true;
//        }
//
//        if (p[0] == '*') {
//            if (p.size() == 1) {
//                return true;
//            }
//            if (p[1] == '*') {
//                return isMatch(s, p.substr(1));;
//            }
//            char x = p[1];
//            for (int i = 0;i < s.size(); i++) {
//                if (s[i] == x || x == '?') {
//                    if(isMatch(s.substr(i), p.substr(1)))
//                    {
//                        return true;
//                    }
//                }
//            }
//        } else if (p[0] == '?') {
//            return isMatch(s.substr(1), p.substr(1));
//        } else {
//            if (p[0] == s[0]) {
//                return isMatch(s.substr(1), p.substr(1));
//            } else {
//                return false;
//            }
//        }
//
//        return false;
//    }
//
//    bool isMatch(string s, string p) {
//         if(p.empty()) return s.empty();
//
//         int m = (int)s.size();
//         int n = (int)p.size();
//
//         bool dp[m+1][n+1];
//         memset(dp, 0, (m+1)*(n+1)*sizeof(bool));
//         dp[0][0] = true;
//
//         for (int j = 1; j <= n; j++){
//             if (p[j - 1] == '*'){
//                 dp[0][j] = dp[0][j - 1];
//             }
//         }
//
//         for (int i = 1; i <= m; i++) {
//             for (int j = 1; j <= n; j++) {
//                if (p[j - 1] == '*') {
//                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
//                } else if (p[j - 1] == '?' ||  s[i - 1] == p[j - 1]) {
//                    dp[i][j] = dp[i - 1][j - 1];
//                } else {
//                    dp[i][j] = false;
//                }
//             }
//         }
//         return dp[m][n];
//     }



      bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        int m = (int)s.size(), n = (int)p.size();
        bool dp[m+1][n+1];
        memset(dp, 0, (m+1)*(n+1)*sizeof(bool));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            if (p[i-1] == '*') {
                dp[0][i] = dp[0][i-1];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                } else if (p[j-1] == '?' || p[j-1] == s[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[m][n];
     }
    // 正则表达式
    // ? 表示任何单个字符
    // * 表示0个或任意个字符
    void Leetcode::main_44() {
        cout << isMatch("babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb", "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a") << " : false" << endl;
        cout << isMatch("c", "*?*") << " : true" << endl;
        cout << isMatch("abefcdgiescdfimde", "ab*cd?i*de") << " : true" << endl;
        cout << isMatch("aa", "a") << " : false" << endl;
        cout << isMatch("aa", "*") << " : true" << endl;
        cout << isMatch("cb", "?a") << " : false" << endl;
        cout << isMatch("adceb", "*a*b") << " : true" << endl;
        cout << isMatch("acdcb", "a*c?b") << " : false" << endl;
    }
  
}
