//
//  Leetcode84.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/16.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {


    // 超时
    int largestRectangleArea2(vector<int>& heights) {
        int n = (int)heights.size();
        if (n == 0) return 0;

        int res = heights[0];
        for (int i = 0;i < heights.size();i++) {
            int minRec = heights[i];
            int minHeight = heights[i];
            for (int j = i-1;j >= 0 ;j--) {
                int width = i - j + 1;
                minHeight = min(minHeight, heights[j]);
                if (minHeight * width > minRec) {
                    minRec = minHeight * width;
                }
            }

            res = max(res, minRec);
        }
        return res;
    }

    int largestRectangleArea3(vector<int>& heights) {
        int n = (int)heights.size();

        int res = 0;
        for (int i = 0; i < n; i++) {
            int h = heights[i];
            int l = i, r = i;
            while (l >= 0 && h <= heights[l]) l--;
            while (r < n && h <= heights[r]) r++;
            res = max(res, h * (r - l - 1));
        }
        return res;
    }

     int largestRectangleArea(vector<int>& a) {
           int n = (int)a.size();
           int i = 0, maxarea = 0;
           stack<int> s;
           while(i<n) {
               if(s.empty()|| a[s.top()] <= a[i]) {
                    s.push(i++);
               } else {
                   int t = s.top();
                   s.pop();
                   int area = a[t] * (s.empty() ? i : i-s.top()-1);
                   maxarea = max(maxarea,area);
                   cout << "max: " << maxarea << " area: " << area << endl;
               }
           }

           cout << "===================="<< endl;

           while(!s.empty()) {
               int t = s.top();
               cout << "t : " << t << endl;
               s.pop();
               int area =  a[t] * (s.empty() ? i : i-s.top()-1);
               maxarea = max(maxarea,area);
               cout << "max: " << maxarea << " area: " << area << endl;
           }

           return maxarea;
        }

    // 给定一个数组, 数组组成一个柱状图, 柱状宽度为1, 求最大矩形面积
    void Leetcode::main_84() {
        vector<int> vec{2,1,5,6,2,3};
        cout << largestRectangleArea(vec);
    }
}
