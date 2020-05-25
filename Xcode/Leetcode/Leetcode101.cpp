//
//  Leetcode101.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/23.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // 将right树的left和right交换后和left相等
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        TreeNode *leftTree = root->left;
        TreeNode *rightTree = root->right;

        return isTreeNodeEqual(leftTree, rightTree);
    }

    // 判断一个树是否左右对称
    void Leetcode::main_101() {
        TreeNode *node1 = generateTreeNode(vector<int *>{new int(1), new int(2), new int(2), new int(3), new int(4), new int(4), new int(3)});
        cout << "true | " << isSymmetric(node1) << endl;
        TreeNode *node2 = generateTreeNode(vector<int *>{new int(1), new int(2), new int(2), nullptr, new int(3), nullptr, new int(3)});
        cout << "false | " << isSymmetric(node2) << endl;

    }
}
