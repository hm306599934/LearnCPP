//
//  Leetcode230.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/4.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    void kthSmallestHelper(TreeNode* root,int target,int &count,int &res) {
        if (!root) return;
        kthSmallestHelper(root->left,target,count,res);
        count++;
        if (count == target) {
            res = root->val;
            return;
        }
        kthSmallestHelper(root->right, target, count, res);
    }

    int kthSmallest(TreeNode* root, int k) {
        int res = 0, count = 0;
        kthSmallestHelper(root, k, count, res);
        return res;
    }

    // 求BST第k小的数
    void Leetcode::main_230() {
        TreeNode *a1 = new TreeNode(5);
        TreeNode *a2 = new TreeNode(3);
        TreeNode *a3 = new TreeNode(6);
        TreeNode *a4 = new TreeNode(2);
        TreeNode *a5 = new TreeNode(4);
        TreeNode *a6 = new TreeNode(1);
        a1->left = a2;
        a1->right = a3;
        a2->left = a4;
        a2->right = a5;
        a4->left = a6;
        cout << "3 : " << kthSmallest(a1,3) << endl;
//        TreeNode *n1 = new TreeNode(3);
//        TreeNode *n2 = new TreeNode(1);
//        TreeNode *n3 = new TreeNode(4);
//        TreeNode *n4 = new TreeNode(2);
//        n1->left = n2;
//        n1->right = n3;
//        n2->right = n4;
//        cout << "1 : " << kthSmallest(n1,1) << endl;
    }
}
