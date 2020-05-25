//
//  Leetcode206.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/25.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *after = nullptr;
        while (head != nullptr && head->next != nullptr) {
            ListNode *temp = new ListNode(head->val);
            temp->next = after;
            after = temp;
            head = head->next;
        }
        head -> next = after;
        return head;
    }

    // 单向链表反转
    void Leetcode::main_206() {
        vector<int> v1{};
        ListNode *head = generateListNode(v1);
        head = reverseList(head);
        cout << "end" << endl;
    }
}
