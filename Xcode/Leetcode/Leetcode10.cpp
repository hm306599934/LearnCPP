//
//  Leetcode10.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/11.
//  Copyright © 2019 Airactart. All rights reserved.
//


#include "Header.hpp"
#include "Helper.hpp"
using namespace std;

namespace Jimmy {

namespace Leetcode10 {
    bool isMatch2(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }

        bool isFirstMatch = !s.empty() && (p[0] == s[0] || p[0] == '.');

        if (p.size() > 1 && p[1] == '*') {
            return isMatch2(s, p.substr(2)) || (isFirstMatch && isMatch2(s.substr(1), p));
        } else {
            return isFirstMatch && isMatch2(s.substr(1), p.substr(1));
        }
    }

    bool isMatch(string s, string p) {
        int m = (int)p.size();
        int n = (int)s.size();

        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        // s,p都为空时为true
        f[0][0] = true;

        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                int ii = i - 1;
                int jj = j - 1;
                if (p[ii] == '*' && i > 1) {
                    f[i][j] = f[ii-1][j];
                    if (jj >= 0 && (p[ii-1] == s[jj] || p[ii-1] == '.')) {
                        f[i][j] = f[i][j] || f[i][jj];
                    }
                } else {
                    f[i][j] = jj >= 0 && (p[ii] == s[jj] || p[ii] == '.') && f[ii][jj];
                }
            }
        }

        return f[m][n];
    }
}

    using namespace Jimmy::Leetcode10;
    void Leetcode::main_10() {
        cout << isMatch("aab","c*a*b") <<endl;
    }
}
