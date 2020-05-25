//
//  Leetcode116.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/25.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // 递归
    // left->next: super->right
    // right->next: super->next->left
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        if (root->left != nullptr) {
            root->left->next = root->right;
        }
        if (root->right != nullptr && root->next != nullptr) {
            root->right->next = root->next->left;
        }

        connect(root->left);
        connect(root->right);

        return root;
    }
    
    void Leetcode::main_116() {
        Node *node1 = Node::generateNode(vector<int*>{new int(1), new int(2), new int(3),new int(4), new int(5), new int(6), new int(7)});
        Node *res1 = connect(node1);
        cout << node1->val<<endl;
    }
}
