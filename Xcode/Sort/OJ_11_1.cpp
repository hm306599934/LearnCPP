//
//  OJ_11_1.cpp
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

void myQuicksort(vector<int>& nums, int l, int r) {
    if (l < r) {
        int i = l, j = r, x = nums[l];
        while (i < j) {
            while (i < j && x > nums[j]) j--;
            if (i < j) nums[i++] = nums[j];
            while (i < j && nums[i] > x) i++;
            if (i < j) nums[j--] = nums[i];
        }
        nums[i] = x;
        myQuicksort(nums, l, i-1);
        myQuicksort(nums, i+1, r);
    }
}

int method1(vector<int>& nums, int money) {
    if (nums.empty())   return 0;
    int n = (int)nums.size();
    myQuicksort(nums, 0, n-1);

    int count = 0;
    int i = 0;
    for (int num : nums) {
        if (count >= money) {
            break;
        }
        count += num;
        i++;
    }

    return n - i;
}

void OJ::main_11_1()
{
    int n;
    cin >> n;
    vector<int> res;
    while (n > 0) {
        int money;
        cin>>money;
        int count;
        cin>>count;
        vector<int> vec;
        while (count > 0) {
            int a;
            cin>>a;
            vec.push_back(a);
            count--;
        }
        res.push_back(method1(vec, money));
        n--;
    }

    for (int aa : res) {
        cout << aa<< endl;
    }
}

}
