//
//  NodeHelper.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/25.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "NodeHelper.hpp"


namespace Jimmy {

    // 递归设置节点, 根据当前节点计算左右节点
    void recrutionNode(Node *node, vector<int*> &vec, int index, int level) {

        if (index >= vec.size()) return;
        // 左子节点
        int leftIndex = index * 2 + 1;
        if (leftIndex < vec.size() && vec[leftIndex] != nullptr) {
            int leftVal = *vec[leftIndex];
            Node *leftNode = new Node(leftVal);
            node->left = leftNode;
            recrutionNode(leftNode, vec, leftIndex, level+1);
        }

        // 右子节点
        int rightIndex = leftIndex + 1;
        if (rightIndex < vec.size() && vec[rightIndex] != nullptr) {
            int rightVal = *vec[rightIndex];
            Node *rightNode = new Node(rightVal);
            node->right = rightNode;
            recrutionNode(rightNode, vec, rightIndex,level+1);
        }
    }

    Node* Node::generateNode(vector<int*> vec) {
        int n = (int)vec.size();
        if (n == 0) return nullptr;

        // 总层数
        Node *root = new Node(*vec[0]);
        recrutionNode(root, vec, 0, 0);

        return root;
    }
}
