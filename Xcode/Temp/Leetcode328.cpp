//
//  Leetcode328.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/25.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *res = head;

        ListNode *odd = head;
        ListNode *oddHead = head;
        head = head->next;
        odd->next = nullptr;
        if (head == nullptr) {
            return res;
        }
        ListNode *even = head;
        ListNode *evenHead = head;
        head = head->next;
        even->next = nullptr;

        int i = 0;
        while (head != nullptr) {
            if (i++ % 2 == 1) {
                even->next = head;
                head = head->next;
                even = even->next;
                even->next = nullptr;
            } else {
                odd->next = head;
                head = head->next;
                odd = odd->next;
                odd->next = nullptr;
            }
        }

        odd->next = evenHead;
        return oddHead;
    }

    // 链表，将偶数序号的节点放到后面
    void Leetcode::main_328() {
        ListNode* head = generateListNode(vector<int>{1,2,3,4,5,6,7});
        printListNode(oddEvenList(head));
    }
}
