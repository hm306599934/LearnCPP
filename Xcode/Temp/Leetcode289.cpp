//
//  Leetcode289.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/17.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    int gameOfLifeCount(vector<vector<int>>& board,int i,int j) {
        int res = 0;
        int rNum = (int)board.size();
        int cNum = (int)board[0].size();

        if (j-1 >= 0 && board[i][j-1] == 1) {
            res++;
        }
        if (i+1 < rNum && j-1 >= 0 && board[i+1][j-1] == 1) {
            res++;
        }
        if (i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] == 1) {
            res++;
        }
        if (i+1 < rNum && board[i+1][j] == 1) {
            res++;
        }
        if (i-1 >= 0 && board[i-1][j] == 1) {
            res++;
        }
        if (j+1 < cNum && board[i][j+1] == 1) {
            res++;
        }
        if (i+1 < rNum && j+1 < cNum && board[i+1][j+1] == 1) {
            res++;
        }
        if (i-1 >= 0 && j+1 < cNum && board[i-1][j+1] == 1) {
            res++;
        }
        return res;
    }

    // 游戏人生，二维数组，元素为0或1，满足以下4个条件需要更新
    // 当周围小于2个1，置为0
    // 当周围大于3个1，置为0
    // 当周围有2或3个1，置为1
    // 当本身为0且周围有3个1，置为1
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;
        // 设置标志位，每次调整后，有元素变化就将标志位置为1
        int rNum = (int)board.size();
        int cNum = (int)board[0].size();

        map<pair<int, int>,bool> m_map;

        for (int i = 0;i < rNum;i++) {
            for (int j = 0;j < cNum;j++) {
                int count = gameOfLifeCount(board, i, j);
                if (count < 2 || count > 3) {
                     m_map[make_pair(i, j)] = false;
                     continue;
                }
                if (board[i][j] == 1) {
                    if (count == 2 || count == 3) {
                        m_map[make_pair(i, j)] = true;
                    }
                } else {
                    if (count == 3) {
                        m_map[make_pair(i, j)] = true;
                    }
                }
            }
        }

        map<pair<int, int>,bool>::iterator iter = m_map.begin();
        while(iter != m_map.end()) {
            int i= iter->first.first;
            int j= iter->first.second;
            board[i][j] = iter->second ? 1 : 0;;
            iter++;
        }
    }

    void Leetcode::main_289() {
        vector<vector<int>> board{{0,1,0},
                                  {0,0,1},
                                  {1,1,1},
                                  {0,0,0}};
        gameOfLife(board);
        print2DVector(board);
    }
}
