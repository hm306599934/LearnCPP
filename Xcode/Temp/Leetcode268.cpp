//
//  Leetcode268.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/10.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    int missingNumber1(vector<int>& nums) {
        vector<int> vec(nums.size()+1,0);

        for (int a : nums) {
            vec[a] = 1;
        }

        for (int i = 0;i < vec.size();i++) {
            if (vec[i] == 0) {
                return i;
            }
        }

        return (int)nums.size();
    }

      int missingNumber(vector<int>& nums)
      {
          if (nums.empty()) return 0;
          int all = 0x0;
          int cur = 0x0;
          for (int i = 0; i < nums.size()+1; i++) {
              all = all ^ i;
              if (i != nums.size()) {
                  cur = cur ^ nums[i];
              }
          }
          return (all ^ cur);
      }

    void Leetcode::main_268() {
        vector<int> vec1{0,1};
        vector<int> vec2{1};
        vector<int> vec{9,6,4,2,3,5,7,0,1};
        cout << missingNumber(vec1) << endl;
    }
}
