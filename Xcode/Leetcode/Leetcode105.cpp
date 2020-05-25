//
//  Leetcode105.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/25.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // 递归
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() <= 0) return nullptr;
        TreeNode* root = nullptr;

        int val = preorder[0];
        if (root == nullptr) {
            root = new TreeNode(val);
        };

        vector<int>::iterator iter = find(inorder.begin(),inorder.end(), val);
        int n = 0;
        if (iter != inorder.end()){
          // 迭代器位置
           n = (int)distance(inorder.begin(),iter);
        }
        vector<int> leftInorder = vector<int>(inorder.begin(), inorder.begin() + n);
        vector<int> rightInorder = vector<int>(inorder.begin() + n + 1, inorder.end());
        vector<int> leftPreorder = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
        vector<int> rightPreorder = vector<int>(preorder.begin() + 1 + leftInorder.size(), preorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }

    TreeNode* buildTreeRecrution (vector<int>& preorder, vector<int>& inorder, int left, int right, int &index) {
        if (index >= preorder.size()) return nullptr;

        while (left < right) {
            if (preorder[index] == inorder[left]) break;
            left++;
        }
        if (left >= right) return nullptr;

        TreeNode *root = new TreeNode(preorder[index++]);
        root->left = buildTreeRecrution(preorder, inorder, 0, left, index);
        root->right = buildTreeRecrution(preorder, inorder, left + 1, right ,index);
        return root;
    }
    // 递归2
    TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        TreeNode* result = buildTreeRecrution(preorder, inorder, 0, (int)preorder.size(), index);
        return result;
    }

    void Leetcode::main_105() {
        vector<int> preorder{3,9,20,15,7};
        vector<int> inorder{9,3,15,20,7};
        buildTree(preorder, inorder);
    }
}
