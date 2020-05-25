//
//  Leetcode237.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/4.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    void deleteNode(ListNode* node) {
        if (node == nullptr) return;
        ListNode *tmp = node;
        while (node->next != nullptr) {
            node->val = node->next->val;
            tmp = node;
            node = node->next;
        }
        tmp->next = nullptr;
    }

    void Leetcode::main_237() {
        vector<int> vec{4,5,1,9};
        ListNode *root = generateListNode(vec);
        ListNode *n = root->next;
        deleteNode(n);
    }
}
