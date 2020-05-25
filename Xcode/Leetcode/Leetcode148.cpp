//
//  Leetcode148.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/5.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // 冒泡
    // 先把最小的节点扣出来
    ListNode* sortList2(ListNode* head) {
        ListNode *res = nullptr; // 最小的节点
        ListNode *last = head;

        while (head != nullptr) {
            ListNode *left = head;
            ListNode *min = head;
            ListNode *minPre = head;

            while(left->next != nullptr) {
                if (left->next->val < min->val) {
                    min = left->next;
                    minPre = left;
                    continue;
                }
                left = left->next;
            }
            minPre->next = min->next;
            if (min == head) {
                head = head->next;
            }
            if (res == nullptr) {
                last = min;
                res = min;
            } else {
                last->next = min;
                last = last->next;
            }
        }

        return res;
    }


    ListNode* partition(ListNode* start, ListNode* end) {
        ListNode* p1 = start;
        ListNode* p2 = start->next;
        for (; p2 && p2 != end; p2 = p2->next) {
            if (p2->val < start->val) {
                p1 = p1->next;
                swap(p1->val, p2->val);
            }
        }
        swap(p1->val, start->val);
        return p1;
    }

//    void quickSort(ListNode* start, ListNode* end) {
//        if (start == end) return ;
//        if (start->next == end) return ;
//
//        ListNode* mid = partition(start, end);
//        quickSort(start, mid);
//        quickSort(mid->next, end);
//    }
//
//
//
//    ListNode* sortList(ListNode* head) {
//        quickSort(head, NULL);
//        return head;
//    }
//
//



    ListNode* merge(ListNode* a, ListNode* b) {
          if (a == NULL) return b;
          if (b == NULL) return a;

          ListNode* res;

          if (a->val < b->val) {
              res = a;
              res->next = merge(a->next, b);
          } else {
              res = b;
              res->next = merge(a, b->next);
          }

          return res;
      }

    void divide(ListNode* head, ListNode** a, ListNode** b) {
          ListNode* slow = head;
          ListNode* fast = head->next;

          while(fast && fast->next) {
              slow = slow->next;
              fast = fast->next->next;
          }

          *a = head;
          *b = slow->next;
          slow->next = NULL;
      }

    ListNode* mergeSort(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* a;
        ListNode* b;

        divide(head, &a, &b);
        a = mergeSort(a);
        b = mergeSort(b);
        return merge(a, b);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }


    void Leetcode::main_148() {

        ListNode *node = generateListNode(vector<int>{1,4,2,6,3});
        node = sortList(node);
        cout << "SortList" << endl;
    }
}
