//
//  Leetcode130.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/28.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // 递归找到闭环存储到vec
    void solveRecrution(vector<vector<char>>& board, int i, int j) {
        cout << "i: " << i << " j: " << j <<endl;
        board[i][j] = '?';
        if (i > 0 && board[i-1][j] == 'O') {
            solveRecrution(board, i-1, j);
        }
        if (i + 1 < board.size() && board[i+1][j] == 'O') {
            solveRecrution(board, i+1, j);
        }
        if (j > 0 && board[i][j-1] == 'O') {
            solveRecrution(board, i, j-1);
        }
        if (j + 1 <board[i].size() && board[i][j+1] == 'O') {
            solveRecrution(board, i, j+1);
        }
    }

    // 递归
    // 从左上到右下
    void solve(vector<vector<char>>& board) {
        if (board.size() < 2) return ;
        int row = (int)board.size();
        int col = (int)board[0].size();

        for (int j = 0; j < col; ++j) {
            if (board[0][j] == 'O') {
                solveRecrution(board,0,j);
            }
            if (board[row-1][j] == 'O') {
                solveRecrution(board, row-1, j);
            }
        }

        for (int i = 1; i < row-1; ++i) {
            if (board[i][0] == 'O') {
                solveRecrution(board,i,0);
            }
            if (board[i][col-1] == 'O') {
                solveRecrution(board,i,col-1);
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
            }
        }
    }


    // X包围O的时候将O都改成X
    void Leetcode::main_130() {

        vector<vector<char>> a{
        {'O', 'O'},
        {'O', 'O'},
        };
        vector<vector<char>> board9{
        {'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O'},
        {'O', 'O', 'O', 'X', 'X', 'X', 'X', 'O'},
        {'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O'},
        {'X', 'O', 'X', 'O', 'O', 'X', 'X', 'X'},
        {'O', 'X', 'O', 'X', 'X', 'X', 'O', 'O'},
        {'O', 'X', 'X', 'O', 'O', 'X', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'X', 'X', 'O', 'O'},
        {'O', 'X', 'X', 'X', 'X', 'O', 'X', 'X'},
        };

        vector<vector<char>> board8{
                   {'X', 'X', 'X', 'X'},
                   {'X', 'O', 'O', 'X'},
                   {'X', 'O', 'O', 'X'},
                   {'X', 'X', 'X', 'X'}};

        vector<vector<char>> board7{
            {'O', 'O', 'O', 'O', 'O', 'O'},
            {'O', 'X', 'X', 'X', 'X', 'O'},
            {'O', 'X', 'O', 'O', 'X', 'O'},
            {'O', 'X', 'O', 'O', 'X', 'O'},
            {'O', 'X', 'X', 'X', 'X', 'O'},
            {'O', 'O', 'O', 'O', 'O', 'O'}};

        vector<vector<char>> board0{
            {'X', 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'O'},
            {'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
            {'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X'},
            {'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O'},
            {'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
            {'X', 'X', 'O', 'X', 'X', 'O', 'O', 'X', 'X', 'X'},
            {'O', 'X', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'O'},
            {'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X', 'X', 'O', 'X', 'X', 'O', 'O'},
            {'X', 'X', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'O'}
        };

        vector<vector<char>> board1{
                    {'X', 'X', 'X', 'X'},
                    {'X', 'O', 'O', 'X'},
                    {'X', 'X', 'O', 'X'},
                    {'X', 'O', 'X', 'X'}};

        vector<vector<char>> board2{
                    {'O', 'X', 'O', 'O', 'X', 'X'},
                    {'O', 'X', 'X', 'X', 'O', 'X'},
                    {'X', 'O', 'O', 'X', 'O', 'O'},
                    {'X', 'O', 'X', 'X', 'X', 'X'},
                    {'O', 'O', 'X', 'O', 'X', 'X'},
                    {'X', 'X', 'O', 'O', 'O', 'O'}};

        vector<vector<char>> board3{
                    {'X', 'X', 'X', 'X', 'X'},
                    {'X', 'O', 'O', 'O', 'X'},
                    {'X', 'X', 'O', 'O', 'X'},
                    {'X', 'X', 'X', 'O', 'X'},
                    {'X', 'O', 'X', 'X', 'X'}};

        vector<vector<char>> board4{
                    {'X', 'X', 'X', 'X', 'X'},
                    {'X', 'X', 'X', 'O', 'X'},
                    {'X', 'X', 'O', 'O', 'X'},
                    {'X', 'O', 'O', 'O', 'X'},
                    {'X', 'X', 'X', 'X', 'X'}};

        vector<vector<char>> board5{
                    {'X', 'X', 'X', 'X', 'X'},
                    {'X', 'O', 'X', 'X', 'X'},
                    {'X', 'O', 'O', 'X', 'X'},
                    {'X', 'O', 'O', 'O', 'X'},
                    {'X', 'X', 'X', 'X', 'X'}};

        vector<vector<char>> board6{
                    {'X', 'X', 'X', 'X', 'X'},
                    {'X', 'O', 'O', 'O', 'X'},
                    {'X', 'O', 'O', 'X', 'X'},
                    {'X', 'O', 'X', 'X', 'X'},
                    {'X', 'X', 'X', 'X', 'X'}};

        vector<vector<char>> board = board2;
        solve(board);
        Helper::print2DCharVector(board);
        //Helper::print2DCharVector(board0);
    }
}
