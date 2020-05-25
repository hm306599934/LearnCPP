//
//  Leetcode102.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/24.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {
    // 递归读取节点
    // 先序遍历
    vector<vector<int>> res;
    void readTreeNode(TreeNode *root, int level) {
        if (root == nullptr) return;
        cout << root->val << " | level: " << level << endl;
        if (level >= res.size()) {
            res.push_back(vector<int>{});
        }
        res[level].push_back(root->val);
        readTreeNode(root->left, level+1);
        readTreeNode(root->right, level+1);
    }

    vector<vector<int>> levelOrder1(TreeNode* root) {
        readTreeNode(root, 0);
        return res;
    }

    // queue
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            vector<int> vec;
            int size = (int)q.size();
            for (int i = 0; i < size;i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node == nullptr) continue;
                vec.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            if (!vec.empty()) res.push_back(vec);
        }

        return res;
    }

    // 将树的值按层输出到一个二维数组
    void Leetcode::main_102() {
        TreeNode* node1 = generateTreeNode(vector<int*>{new int(3),new int(9),new int(20),nullptr,nullptr,new int(15),new int(7)});
        vector<vector<int>> res1 = levelOrder(node1);
        
    }
}
