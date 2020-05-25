//
//  Leetcode98.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/24.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    stack<int> s;
    void inorderRead(TreeNode* root) {
        if (root == nullptr) return;

        inorderRead(root->left);
        if (s.empty()) {
            s.push(root->val);
        } else {
            if ((s.top() < root->val)) {
                s.pop();
            }
            s.push(root->val);
        }
        inorderRead(root->right);
    }


    bool isValidBST(TreeNode* root) {
        inorderRead(root);
        return s.size() <= 1;
    }

    void Leetcode::main_98() {
        TreeNode *node1 = generateTreeNode(vector<int *>{new int(2), new int(1), new int(3)});
        cout << "true | " << isValidBST(node1) << endl;

        TreeNode *node2 = generateTreeNode(vector<int *>{new int(2), new int(1), new int(4), nullptr, nullptr, new int(3), new int(6)});
        cout << "false | " << isValidBST(node2) << endl;

    }
}
