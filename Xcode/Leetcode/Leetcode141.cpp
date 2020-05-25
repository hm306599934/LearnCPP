//
//  Leetcode141.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/28.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {


    // 2 point
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast != slow) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }

        return true;
    }

    // set
    bool hasCycle2(ListNode *head) {
        set<ListNode*> s;
        set<ListNode*>::iterator iter;
        while(head != nullptr) {
            iter = s.find(head);
            if (iter != s.end()) {
                return true;
            } else {
                s.insert(head);
            }

            head = head->next;
        }

        return false;
    }
    
    void Leetcode::main_141() {
        ListNode *node1 = new ListNode(3);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(0);
        ListNode *node4 = new ListNode(-4);
        node1->next = node2;
        node2->next = node1;
        node2->next = node3;
        node3->next = node4;
        node4->next = node2;
        cout << "true | " << hasCycle(node1) << endl;
    }
}
