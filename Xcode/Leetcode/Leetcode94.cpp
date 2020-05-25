//
//  Leetcode94.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/24.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // 递归

    void recrution(TreeNode *root, vector<int> &vec) {
        if (root == nullptr) {
            return;
        }
        recrution(root->left, vec);
        vec.push_back(root->val);
        cout << "root :" << root->val <<endl;
        recrution(root->right, vec);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        recrution(root, res);
        return res;
    }




    // 给定一个二叉树, 输出按中根遍历
    void Leetcode::main_94() {

        vector<int*> vec2{new int(5), new int(1), new int(4), nullptr, nullptr, new int(3), new int(6)};
        generateTreeNode(vec2);

        TreeNode *a = new TreeNode(1);
        TreeNode *b = new TreeNode(2);
        TreeNode *c = new TreeNode(3);
        a->right = b;
        b->left = c;

        printVector(inorderTraversal(a));
    }
}
