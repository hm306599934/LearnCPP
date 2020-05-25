//
//  Leetcode378.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/31.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {


    int kthSmallestHelper2(vector<vector<int>>& matrix,int& x) {
        int n = (int)matrix.size();
        int res = 0;
        for(int i=0; i<n; i++) {
            res += upper_bound(matrix[i].begin(), matrix[i].end(), x) - matrix[i].begin();
        }
        return res;
    }

    int kthSmallestHelper3(vector<vector<int>>& matrix,int& x) {
        int n = (int)matrix.size();
        int res = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if (matrix[i][j] <= x) {
                    res++;
                }
            }
        }
        return res;
    }

    int kthSmallestHelper(vector<vector<int>>& matrix,int& x) {
        int n = (int)matrix.size();
        int res = 0;

        int i = 0,j = 0;

        while(x > matrix[i][n-1]) {
            res += n;
            i++;
        }
        while(x > matrix[n-1][j]) {
            res += n-i;
            j++;
        }
        for(; i<n; i++) {
            for(int k = j; k<n; k++) {
                if (matrix[i][k] <= x) {
                    res++;
                }
            }
        }
        return res;
    }
        //7 8 8 7 8 18
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;

        int n = (int)matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        while (low < high) {
            int mid = (low + high) / 2;
            int pos = kthSmallestHelper(matrix, mid);
            cout << " " << mid << " | "<< pos << " " ;
            if (pos < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        cout  << endl ;
        return low;
    }

    // 找到二维数组中倒数第k小的数
    // 二维数组每行每列都递增
    void Leetcode::main_378() {
        vector<vector<int>> v1{{ 1, 5, 9},
                               {10,11,13},
                               {12,13,15},
                               };
        cout << kthSmallest(v1,8)<<endl;
    }
}
