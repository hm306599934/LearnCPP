//
//  Leetcode149.cpp
//  Xcode
//
//  Created by Jimmy on 2020/1/19.
//  Copyright © 2020 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    int gcd(int a, int b){
        return b == 0 ? a : gcd(b,a%b);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        if (n < 3) return n;
        int res = 1;

        for (int i = 0; i < n-1; i++) {
            int temp = 1;
            unordered_map<string,int> map;
            for (int j = i+1; j < n; j++) {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];

                if (x == 0 && y == 0) {
                    ++temp;
                }  else if (y == 0) {
                    ++map["h"];
                }else if (x == 0) {
                    ++map["v"];
                } else {
                    int temp = abs(gcd(y,x));
                    if (y < 0) temp *= -1;
                    ++map[to_string(y/temp)+to_string(x/temp)];
                }
            }

            res = max(res,temp);
            for (auto i : map)
                res = max(res,i.second+temp);
        }

        return res;
    }

    // 二维坐标上给定多个点,输出一条直线上最多多少个点
    // 可以根据斜率计算在一条直线上
    void Leetcode::main_149() {
        vector<vector<int>> v1{{1,1}, {2,2,}, {3,3}};
        cout << "3 : " << maxPoints(v1) << endl;

        vector<vector<int>> v2{{1,1}, {3,2}, {5,3}, {4,1}, {2,3}, {1,4}};
        cout << "4 : " << maxPoints(v2) << endl;
    }
}
