//
//  Leetcode234.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/4.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;

        ListNode *temp = head;
        int n = 1;
        while(temp->next != nullptr) {
            n++;
            temp = temp->next;
        }

        ListNode *before = nullptr;
        ListNode *root = head;
        ListNode *tmp = root->next;
        for (int i = 0; i < n /2; i++) {
            root->next = before;
            before = root;
            root = tmp;
            tmp = tmp->next;
        }
        ListNode *after = n%2 ? root->next : root;

        for (int i = 0;i < n / 2;i++) {
            if (before->val != after->val) {
                return false;
            } else {
                before = before->next;
                after = after->next;
            }
        }

        return true;
    }



    void Leetcode::main_234() {
        ListNode *node = generateListNode(vector<int>{1,2,3,4,3,2,1});
        cout << "true : " << isPalindrome(node);

    }
}
