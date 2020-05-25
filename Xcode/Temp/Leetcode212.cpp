//
//  Leetcode_212.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/22.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> s;
        vector<vector<pair<int, int>>> v(26);
        for (int i = 0;i < board.size();i++) {
            for(int j = 0;j < board[i].size();j++) {
                v[board[i][j]-'a'].push_back(make_pair(i, j));
            }
        }

        // 找单词
        for (string str : words) {
            for (int i = 0;i < str.size();i++) {
                if (v[str[i]-'a'].size() == 0) {
                    break;
                }
                
            }
        }

        return s;
    }

    // 给定一个二维字符数组和一组单词
    // 保持单词有序, 输出相邻的单词
    void Leetcode::main_212() {
        vector<vector<char>> v1{{'o','a','a','n'},
                                {'e','t','a','e'},
                                {'i','h','k','r'},
                                {'i','f','l','v'}};
        vector<string> w1{"oath","pea","eat","rain"};
        vector<string> r1 = findWords(v1, w1);
        printVector(r1);

        //找到每个单词路径,倒序路径
        //判断是否相邻
    }

}
