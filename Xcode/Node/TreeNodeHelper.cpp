//
//  TreeNodeHelper.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/23.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "TreeNodeHelper.hpp"


namespace Jimmy {

    // 递归设置节点, 根据当前节点计算左右节点
    void recrutionTreeNode(TreeNode *node, vector<int*> &vec, int index, int level) {

        if (index >= vec.size()) return;
        // 左子节点
        int leftIndex = index * 2 + 1;
        if (leftIndex < vec.size() && vec[leftIndex] != nullptr) {
            int leftVal = *vec[leftIndex];
            TreeNode *leftNode = new TreeNode(leftVal);
            node->left = leftNode;
            recrutionTreeNode(leftNode, vec, leftIndex, level+1);
        }

        // 右子节点
        int rightIndex = leftIndex + 1;
        if (rightIndex < vec.size() && vec[rightIndex] != nullptr) {
            int rightVal = *vec[rightIndex];
            TreeNode *rightNode = new TreeNode(rightVal);
            node->right = rightNode;
            recrutionTreeNode(rightNode, vec, rightIndex,level+1);
        }
    }

    // 数可以找到下一个节点, 但是找不到上一个节点
    // 沿着一个分支自顶而下, 只能递归添加新节点
    TreeNode* generateTreeNode(vector<int*> vec) {
        int n = (int)vec.size();
        if (n == 0) return nullptr;

        // 总层数
        TreeNode *root = new TreeNode(*vec[0]);
        recrutionTreeNode(root, vec, 0, 0);

        return root;
    }

    void printTreeNodeInorder(TreeNode* root) {
        if (root == nullptr) return;
        printTreeNodeInorder(root->left);
        cout << root->val << endl;
        printTreeNodeInorder(root->right);
    }

    void printTreeNodePreorder(TreeNode* root) {
        if (root == nullptr) return;
        cout << root->val << endl;
        printTreeNodePreorder(root->left);
        printTreeNodePreorder(root->right);
    }

    void printTreeNodePostorder(TreeNode* root) {
        if (root == nullptr) return;
        printTreeNodePostorder(root->left);
        printTreeNodePostorder(root->right);
        cout << root->val << endl;
    }

    bool isTreeNodeEqual(TreeNode *left, TreeNode *right) {
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr || right == nullptr) return false;

        if (left->val != right->val) {
            return false;
        }

        if (isTreeNodeEqual(left->left, right->right) &&
            isTreeNodeEqual(left->right, right->left)) {
            return true;
        }

        return false;
    }
}
