//
//  ListNodeHelper.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/28.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "ListNodeHelper.hpp"

namespace Jimmy {

    ListNode* generateListNode(vector<int> vec) {
        ListNode *head = nullptr;
        ListNode *root = nullptr;
        vector<int>::iterator iter = vec.begin();
        while(iter != vec.end()) {
            ListNode *node = new ListNode(*iter);
            if (root == nullptr) {
                root = node;
                head = node;
            } else {
                root->next = node;
                root = root->next;
            }
            iter++;
        }
        return head;

    }
}
