//
//  Leetcode324.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/27.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    void wiggleSort2(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int k = (int)nums.size()-1;
        int j= ((int)nums.size()-1)/2;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = temp[j--];
            } else {
                nums[i] = temp[k--];
            }
        }
    }

    bool comp(int a,int b) {
        return a > b;
    }

    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end(), comp);

        int k = 0;
        int j= ((int)nums.size())/2;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = temp[j++];
            } else {
                nums[i] = temp[k++];
            }
        }
    }

    void Leetcode::main_324() {
        vector<int> v3{4,5,5,6};
        vector<int> v2{1,1,2,1,2,2,1};
        vector<int> v1{1,5,3,2,6,4};
        vector<int> v4{1,2,3,4,5,6,7,8,9};
        wiggleSort(v4);
        printVector(v4);
    }
}
