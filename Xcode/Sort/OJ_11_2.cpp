//
//  OJ_11_2.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/20.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <unordered_map>
#include <stdlib.h>
using namespace std;

namespace Jimmy {

bool isBigger(float x, float y, float num, float v) {
    float res = (x-y) / y > (num-v) / v;
    return res > 0 || (res == 0 && y < v);
}


void myQuicksort2(vector<int>& nums, vector<int>& vec, int l, int r) {
    if (l < r) {
        int i = l, j = r, x = nums[l], y = vec[l];
        while (i < j) {
            while (i < j && isBigger(x, y, nums[j], vec[j])) j--;
            if (i < j) {
                nums[i] = nums[j];
                vec[i] = vec[j];
                i++;
            }
            while (i < j && isBigger(x, y, nums[i], vec[i])) i++;
            if (i < j) {
                nums[j] = nums[i];
                vec[j] = vec[i];
                j--;
            }
        }
        nums[i] = x;
        vec[i] = y;
        myQuicksort2(nums, vec,l, i-1);
        myQuicksort2(nums, vec,i+1, r);
    }
}

int method2(vector<int>& v1, vector<int>& v2, int money) {
    if (v1.empty()) return 0;
    int len = (int)v1.size();
    myQuicksort2(v1, v2, 0, len-1);

    int num = 0;
    int res = 0;
    for (int i = 0; i< len;i++) {
        if (num + v2[i] > money) {
            continue;
        }
        num += v2[i];
        res += v1[i] - v2[i];
    }

    return res;
}

void OJ::main_11_2()
{
    vector<int> vv1{100,50,50,50,50,60};
    vector<int> vv2{50,20,20,20,30,40};

    cout << method2(vv1,vv2,50) << endl;
    return;

    int n;
    cin >> n;
    int money;
    cin >> money;
    vector<int> v1;
    vector<int> v2;
    while (n > 0) {
        int oldPrice;
        cin>>oldPrice;
        int newPrice;
        cin>>newPrice;
        v1.push_back(oldPrice);
        v2.push_back(newPrice);
        n--;
    }

    cout << method2(v1,v2,money) << endl;
}

}

