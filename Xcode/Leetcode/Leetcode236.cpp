//
//  Leetcode236.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/4.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    bool lcapPath2(TreeNode* root, TreeNode* p, vector<TreeNode*>& path) {
        if (!root) return false;
        path.push_back(root);
        if (root == p || lcapPath2(root->left, p, path) || lcapPath2(root->right, p, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pVec;
        lcapPath2(root, p, pVec);
        vector<TreeNode*> qVec;
        lcapPath2(root, q, qVec);

        TreeNode* res = nullptr;
        for (int i = 0; i < min(pVec.size(),qVec.size()); i++) {
            if (pVec[i] == qVec[i]) {
                res = pVec[i];
            }
        }
        return res;
    }

    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        if(root == NULL || root == A || root == B) return root;

        TreeNode *l = lowestCommonAncestor2(root->left,A,B);
        TreeNode *r = lowestCommonAncestor2(root->right,A,B);
        if(l && r) return root;
        return l?l:r;
    }

    TreeNode* lowestCommonAncestor4(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return root;
        stack<TreeNode*> s;
        vector<TreeNode*> vec; // p和q的公共祖先
        bool tag1 = false; // true:找到p
        bool tag2 = false; // true:找到q
        s.push(root);
        TreeNode* lastRoot = root;
        while (!s.empty()) // lastRoot(区分从左/右孩子返回)
        {
            root = s.top();
            if (root == p) {
                if(tag1 == false && tag2 == false)
                    vec.push_back(root);
                tag1 = true;
            }
            else if (root == q) {
                if (tag2 == false && tag1 == false)
                    vec.push_back(root);
                tag2 = true;
            }
            if (!tag1 && !tag2)
                vec.push_back(root); // 公共祖先入vector
            // 找到p,q并且root在公共祖先数组中
            if (tag1 && tag2 && find(vec.begin(), vec.end(), root) != vec.end())
                return root;
            // root的孩子节点还没访问
            if (lastRoot != root->right)
            {
                if (lastRoot != root->left) {
                    if (root->left != nullptr) {
                        s.push(root->left);
                        continue;
                    }
                }
                if (root->right != nullptr) {
                    s.push(root->right);
                    continue;
                }
            }
            // 孩子节点访问完，弹栈向上回溯
            lastRoot = root;
            s.pop();
        }
        return nullptr;
    }


    // 寻找LCA（最小公共祖先）
    void Leetcode::main_236() {
        TreeNode *root = new TreeNode(3);
        TreeNode *n1 = new TreeNode(5);
        TreeNode *n2 = new TreeNode(1);
        TreeNode *n3 = new TreeNode(6);
        TreeNode *n4 = new TreeNode(2);
        TreeNode *n5 = new TreeNode(0);
        TreeNode *n6 = new TreeNode(8);
        TreeNode *n7 = new TreeNode(7);
        TreeNode *n8 = new TreeNode(4);
        root->left = n1;
        root->right = n2;
        n1->left = n3;
        n1->right = n4;
        n2->left = n5;
        n2->right = n6;
        n4->left = n7;
        n4->right = n8;
        TreeNode *res = lowestCommonAncestor4(root, n3, n8);
        cout << "5 : "<< res->val<<endl;
    }
}
