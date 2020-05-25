//
//  TreeNodeHelper.hpp
//  Xcode
//
//  Created by Jimmy on 2019/10/23.
//  Copyright © 2019 Airactart. All rights reserved.
//

#ifndef TreeNodeHelper_hpp
#define TreeNodeHelper_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

namespace Jimmy {
    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    };

    /// 数组转树
    /// @param vec 数组
    TreeNode* generateTreeNode(vector<int*> vec);
    /// 打印树, 中序遍历
    /// @param root 树根节点
    void printTreeNodeInorder(TreeNode* root);
    /// 打印树, 前序遍历
    /// @param root 树根节点
    void printTreeNodePreorder(TreeNode* root);
    /// 打印树, 后序遍历
    /// @param root 树根节点
    void printTreeNodePostorder(TreeNode* root);
    /// 判断树是否相等
    /// @param left 左树
    /// @param right 右树
    bool isTreeNodeEqual(TreeNode *left, TreeNode *right);
}

#endif /* TreeNodeHelper_hpp */
