//
//  Leetcode108.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/25.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    TreeNode* sortedArrayToBSTRecrution(vector<int> &nums, int left, int right) {
        int index = (left + right) / 2;
        if (index < 0 || index >= nums.size()) return nullptr;
        if (left > right) return nullptr;

        int val = nums[index];
        TreeNode *node = new TreeNode(val);
        node->left = sortedArrayToBSTRecrution(nums, left, index - 1);
        node->right = sortedArrayToBSTRecrution(nums, index + 1, right);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTRecrution(nums, 0, (int)nums.size());
    }

    // 给定一个按升序排列的数组, 输出一个左右子树高度均衡的BST
    void Leetcode::main_108() {

        vector<int> nums{-10,-3,0,5,9};
        TreeNode *node1 = sortedArrayToBST(nums);
        cout << 1 << endl;
    }
}
