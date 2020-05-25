//
//  Leetcode334.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/25.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int a = nums[0],aa = nums[0],b = INT_MIN;
        for (int i = 1; i < nums.size(); i++) {
            if (b == INT_MIN) {
                if (nums[i] > a) {
                    b = nums[i];
                } else {
                    a = nums[i];
                }
            } else if (nums[i] > a && nums[i] < b) {
                b = nums[i];
            } else if (nums[i] > aa && nums[i] < b) {
                a = aa;
                b = nums[i];
            } else if (nums[i] < a) {
                aa = nums[i];
            } else if (b > a && nums[i] > b) {
                return true;
            }
        }
        return false;
    }

    void Leetcode::main_334() {
        vector<int> v6{5,1,5,5,2,5,4};
        cout << "true : " <<increasingTriplet(v6)<<endl;
        vector<int> v5{0,4,2,1,0,-1,-3};
        cout << "false : " <<increasingTriplet(v5)<<endl;
        vector<int> v4{2,4,-2,-3};//1,3,0,4
        cout << "false : " <<increasingTriplet(v4)<<endl;
        vector<int> v1{1,6,3,2,5,4};//1,3,0,4
        cout << "true : " <<increasingTriplet(v1)<<endl;
        vector<int> v2{1,3,0,4};//1,3,0,4
        cout << "true : " <<increasingTriplet(v2)<<endl;
        vector<int> v3{1,3,0,1,2};//1,3,0,4
        cout << "true : " <<increasingTriplet(v3)<<endl;

    }
}
