//
//  Leetcode179.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/14.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    bool isBigger(int a, int b) {
        string aa = to_string(a) + to_string(b);
        string bb = to_string(b) + to_string(a);

        for (int i = 0; i < aa.size(); i++) {
            if (aa[i] == bb[i]) {
                continue;
            }
            return aa[i] > bb[i];
        }
        return false;
    }

    void largestNumberHelper(vector<int>& nums, int l, int r) {
        if (l < r) {
            int i = l, j = r, x = nums[l];
            while (i < j) {
                while (i < j && isBigger(x,nums[j])) j--;
                if (i < j) nums[i++] = nums[j];
                while (i < j && isBigger(nums[i], x)) i++;
                if (i < j) nums[j--] = nums[i];
            }
            nums[i] = x;
            largestNumberHelper(nums, l, i-1);
            largestNumberHelper(nums, i+1, r);
        }
    }
    string largestNumber(vector<int>& nums) {
        vector<int> vec(10,0);
        int n = (int)nums.size();
        largestNumberHelper(nums, 0, n-1);
        if (nums[0] == 0) {
            return "0";
        }
        string res;
        for (int num : nums) {
            res += to_string(num);
        }
        return res;
    }

    void Leetcode::main_179() {
        vector<int> v5{824,938,1399,5607,6973,5703,9609,4398,8247};
        cout << largestNumber(v5) << endl;
        //9609938824824769735703560743981399
        //9609938824824769735703560743981399
//        vector<int> v4{0, 0};
//        cout << largestNumber(v4) << endl;
//
//        vector<int> v3{12, 128};
//        cout << largestNumber(v3) << endl;
//
//        vector<int> v1{3,30,34,5,9};
//        cout << largestNumber(v1) << endl;
//
//        vector<int> v2{10, 2};
//        cout << largestNumber(v2) << endl;
//
        cout << "1 : " << isBigger(34, 30) << endl;
        cout << "1 : " << isBigger(34, 3) << endl;
        cout << "0 : " << isBigger(30, 3) << endl;
        cout << "0 : " << isBigger(12, 128) << endl;
        cout << "0 : " << isBigger(8247, 824) << endl;
        cout << "1 : " << isBigger(12, 121) << endl;

    }
}
