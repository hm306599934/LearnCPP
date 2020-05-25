//
//  Leetcode103.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/25.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // 循环
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int level = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = (int)q.size();
            vector<int> vec;

            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node ==  nullptr) continue;
                vec.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }

            if (vec.size() > 0) {
                if (level % 2 == 1) {
                    reverse(vec.begin(), vec.end());
                }
                res.push_back(vec);
            }
            level++;
        }

        return res;
    }

    void Leetcode::main_103() {
        TreeNode* node1 = generateTreeNode(vector<int*>{new int(3),new int(9),new int(20),nullptr,nullptr,new int(15),new int(7)});
        zigzagLevelOrder(node1);
        TreeNode* node2 = generateTreeNode(vector<int*>{new int(1),new int(2),new int(3),new int(4),nullptr,nullptr,new int(5)});
        zigzagLevelOrder(node2);
    }
}
