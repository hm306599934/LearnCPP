//
//  Leetcode200.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/19.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // 递归
    void numIslandsRecrution(vector<vector<char>>& grid,int i, int j) {
        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[i].size() ||
            grid[i][j] == '0') {
            return ;
        }

        grid[i][j] = '0';
        numIslandsRecrution(grid,i+1,j);
        numIslandsRecrution(grid,i-1,j);
        numIslandsRecrution(grid,i,j+1);
        numIslandsRecrution(grid,i,j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0;i < grid.size();i++) {
            for(int j = 0; j < grid[i].size();j++) {
                if (grid[i][j] == '1') {
                    res++;
                    numIslandsRecrution(grid, i, j);
                }
            }
        }
        return res;
    }

    void Leetcode::main_200() {

        vector<vector<char>> v3{
                        {'1','1','1'},
                        {'0','1','0'},
                        {'1','1','1'},
        };
        cout << "1 : " << numIslands(v3) << endl;
        vector<vector<char>> v2{
                        {'1','1','0','0','0'},
                        {'1','1','0','0','0'},
                        {'0','0','1','0','0'},
                        {'0','0','0','1','1'},
        };
        cout << "3 : " << numIslands(v2) << endl;
        vector<vector<char>> v1{
                        {'1','1','1','1','0'},
                        {'1','1','0','1','0'},
                        {'1','1','0','0','0'},
                        {'0','0','0','0','0'},
        };
        cout << "1 : " << numIslands(v1) << endl;

    }
}
