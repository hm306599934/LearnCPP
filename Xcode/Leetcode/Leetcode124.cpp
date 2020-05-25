//
//  Leetcode124.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/28.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // dp
    // [i][0]表示第i个节点, 0表示没有子树, 1表示左子树, 2表示右子树, 3表示左右都有子树
    int maxPathSum2(TreeNode* root) {


        return 0;
    }


    int maxPathSumHelper(TreeNode* node, int& res) {
        if (node == NULL) return 0;
        int leftMax = max(maxPathSumHelper(node->left, res), 0);
        int rightMax = max(maxPathSumHelper(node->right, res), 0);

        res = max(res, node->val+leftMax+rightMax);
        return node->val + max(leftMax,rightMax);
    }

    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSumHelper(root, res);
        return res;
    }

    void Leetcode::main_124() {
        TreeNode* node1 = generateTreeNode(vector<int*>{new int(1),new int(2),new int(3)});
        cout << maxPathSum(node1) << endl;
        TreeNode* node2 = generateTreeNode(vector<int*>{new int(-10),new int(9),new int(20),nullptr,nullptr,new int(15),new int(7)});
        cout << maxPathSum(node2) << endl;
    }
}
