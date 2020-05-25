//
//  Leetcode_384.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/31.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    class Solution {
    public:
        vector<int> m_nums;
        vector<int> m_shuffle;

        Solution(vector<int>& nums) {
            m_nums = nums;
            m_shuffle = nums;
        }
        vector<int> reset() {
            return m_nums;
        }

        vector<int> shuffle() {
            int n = (int)m_shuffle.size();
            for (int i = 0;i < n;i++) {
                int a = rand() % n;
                int temp = m_shuffle[a];
                m_shuffle[a] = m_shuffle[i];
                m_shuffle[i] = temp;
            }
            return m_shuffle;
        }
    };

    // 给数组洗牌
    void Leetcode::main_384() {
        vector<int> nums{1,2,3};
        Solution *obj = new Solution(nums);
        for(int i = 0;i < 20;i++) {
            printVector(obj->shuffle());
        }
        printVector(obj->reset());
    }
}
