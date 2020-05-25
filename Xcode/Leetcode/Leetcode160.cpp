//
//  Leetcode160.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/4.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        while(headB != nullptr) {
            ListNode *tempA = headA;
            while(tempA != nullptr) {
                if (tempA == headB) {
                    return tempA;
                }
                tempA = tempA->next;
            }
            headB = headB->next;
        }

        return nullptr;
    }

    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {

         ListNode* a = headA;
         ListNode* b = headB;

         while(a != b){
             a = a == NULL ? headB : a->next;
             b = b == NULL ? headA : b->next;
         }

      return b;
     }

     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != nullptr) {
            a = a->next;
            lenA++;
        }
        while (b != nullptr) {
            b = b->next;
            lenB++;
        }

        while (headA && headB) {
            if (lenA > lenB) {
                headA = headA->next;
                lenA--;
            } else if (lenA < lenB) {
                headB = headB->next;
                lenB--;
            } else {
                break;
            }
        }

        while (headA && headB) {
            if (headA == headB) {
                return headA;
            } else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return nullptr;
     }

    // 给出两个链表, 如果有相同的值即合并到一个链表
    void Leetcode::main_160() {
        ListNode *node1 = new ListNode(4);
        ListNode *node2 = new ListNode(1);
        ListNode *node3 = new ListNode(5);
        ListNode *node4 = new ListNode(0);
        ListNode *node5 = new ListNode(1);
        ListNode *node6 = new ListNode(8);
        ListNode *node7 = new ListNode(4);
        ListNode *node8 = new ListNode(5);
        node1->next = node2;
        node2->next = node6;
        node3->next = node4;
        node4->next = node5;
        node5->next = node6;
        node6->next = node7;
        node7->next = node8;


        ListNode *node = getIntersectionNode(node1, node3);
        cout << "123" << endl;
    }
}
