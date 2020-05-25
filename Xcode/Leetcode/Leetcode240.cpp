//
//  Leetcode240.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/20.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

bool searchMatrix2(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int n = (int)matrix.size();
    int m = (int)matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

bool searchMatrixHelper(vector<vector<int>>& matrix, int &target,int r_l,int r_h,int c_l,int c_h) {

    if (r_l > r_h || c_l > c_h || target > matrix[r_h][c_h] || target < matrix[r_l][c_l]) {
        return false;
    }
    while (r_l <= r_h && c_l <= c_h) {
        if (target < matrix[r_l][c_l] || target > matrix[r_h][c_h]) {
            return false;
        }
        if (target < matrix[(r_l+r_h)/2][c_l]) {
            r_h = (r_l+r_h)/2 - 1;
            continue;
        }else if (target > matrix[(r_l+r_h)/2][c_h]) {
            r_l = (r_l+r_h)/2 + 1;
            continue;
        }else if (target < matrix[r_l][(c_l+c_h)/2]) {
            c_h = (c_l+c_h)/2 - 1;
            continue;
        }else if (target > matrix[r_h][(c_l+c_h)/2]) {
            c_l = (c_l+c_h)/2 + 1;
            continue;
        }

        if (target == matrix[(r_l+r_h)/2][(c_l+c_h)/2]) {
            return true;
        }else if (target < matrix[(r_l+r_h)/2][(c_l+c_h)/2]) {
            if (searchMatrixHelper(matrix, target, r_l, (r_l+r_h)/2-1, c_l,c_h) ||
                searchMatrixHelper(matrix, target, (r_l+r_h)/2, r_h, c_l,(c_l+c_h)/2-1)) {
                return true;
            }
        }else if (target < matrix[(r_l+r_h)/2][(c_l+c_h)/2]) {
            if (searchMatrixHelper(matrix, target, r_l, r_h, (c_l+c_h)/2+1,c_h) ||
                searchMatrixHelper(matrix, target, (r_l+r_h)/2+1, r_h, c_l,(c_l+c_h)/2)) {
                return true;
            }
        }

    }


    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int rNum = (int)matrix.size();
    int cNum = (int)matrix[0].size();

    return searchMatrixHelper(matrix,target,0,rNum-1,0,cNum-1);
}


bool searchMatrix3(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int row = 0,col = (int)matrix[0].size()-1;

    while (row < matrix.size() && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] > target){
            col--;
        } else {
            row++;
        }
    }

    return false;
}
//
void Leetcode::main_240() {
    vector<vector<int>> m2{
        { 1, 6,10,13,14,16,21},
        { 3,10,12,18,22,27,29},
        { 3,15,19,20,23,29,34},
        { 8,15,19,25,27,29,39},
        {12,17,24,25,28,29,41},
        {16,22,27,31,31,33,44},
        {20,26,28,35,39,41,45},
        {25,31,34,39,44,45,47}};
    cout << "true : " <<searchMatrix(m2, 39);
    vector<vector<int>> matrix{
            { 1,  4,  7, 11, 15},
            { 2,  5,  8, 12, 19},
            { 3,  6,  9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}};
    //cout << "true : " <<searchMatrix(matrix, 19);

    vector<vector<int>> matrix2{{1,1}};
    //cout << "true : " <<searchMatrix(matrix2, 0);
}

}

