//
//  Leetcode42.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/16.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // 分治
    int trap1(vector<int> &height) {
        int n = (int)height.size();

        int res = 0;
        for (int i = 0;i < n;i++) {

            int l = i;
            while (l >= 0 && height[i]) {

            }

        }
        return res;
    }

    // force
    int trap5(vector<int> &vec) {
        int res = 0;
        for (int i = 0;i < vec.size(); i++) {
            // 找左右比自己高的
            int l = vec[i], r = vec[i];
            for (int j = i-1;j >= 0;j--) {
                if (vec[j] > l) {
                    l = vec[j];
                }
            }
            for (int j = i+1;j < vec.size();j++) {
                if (vec[j] > r) {
                    r = vec[j];
                }
            }
            int h = min(l, r) - vec[i];
            if (h > 0) res += h;
        }

        return res;
    }

    // 2 points
    int trap3(vector<int> &vec) {
        int n = (int)vec.size();
        int res = 0;
        int l = 0, r = n - 1;
        int maxL = 0, maxR = 0;
        while(l < r) {
            if (vec[l] > vec[r]) {
                if (vec[r] > maxR) {
                    maxR = vec[r];
                } else {
                    res += maxR - vec[r];
                }
                r--;
            } else {
               if (vec[l] > maxL) {
                    maxL = vec[l];
               } else {
                    res += maxL - vec[l];
               }
               l++;
            }

        }
        return res;
    }

    // dp
    int trap6(vector<int> &vec) {
        int n = (int)vec.size();
        int res = 0;
        vector<int> dpL(n+1, 0), dpR(n+1, 0);

        for (int i= 0; i < n-1; i++) {
             dpL[i+1] = max(dpL[i], vec[i]);;
             dpR[n-i-2] = max(dpR[n-i-1], vec[n-i-1]);
        }

       for (int i= 0; i < n; i++) {
            int h = min(dpL[i], dpR[i]) - vec[i];
            if (h > 0) {
                res += h;
            }
       }

        return res;
    }

    // stack
     int trap(vector<int> &vec) {
         int res = 0;
         stack<int> s;
         for(int i = 0; i < vec.size(); i++) {
             while (!s.empty() && vec[i] > vec[s.top()]) {
                 int top = s.top();
                 s.pop();
                 if (s.empty()) break;

                 int w = i - s.top() - 1;
                 int h = min(vec[i], vec[s.top()]) - vec[top];
                 res += w * h;
             }
             s.push(i);
         }
         return res;
     }

    // 基本思路: 针对每个元素, 计算左右最大值, 左最大值和右最大值的最小值比当前值大, 则加上
    void Leetcode::main_42() {
        vector<int> a1{0,1,0,2,1,0,1,3,2,1,2,1};
        vector<int> a2{4,2,3};
        vector<int> a3{4,2,0,3,2,5};
        vector<int> a4{0,1,0,2,1,0,1,3,2,1,2,1};

        cout << trap(a1)<<endl; // 6
        cout << trap(a2)<<endl; // 1
        cout << trap(a3)<<endl; // 9
        cout << trap(a4)<<endl; // 6
    }

}
