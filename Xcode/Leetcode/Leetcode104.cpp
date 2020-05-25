//
//  Leetcode104.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/25.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {

            int size = (int)q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node == nullptr) continue;
                q.push(node->left);
                q.push(node->right);
            }
            if (q.size() > 0) level++;
        }
        return level;
    }

    void Leetcode::main_104() {
        TreeNode* node1 = generateTreeNode(vector<int*>{new int(3),new int(9),new int(20),nullptr,nullptr,new int(15),new int(7)});
        cout << "3 | " << maxDepth(node1) << endl;
    }
}
