//
//  Other_Queue.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/28.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    class HMQueue {
    public:
        ListNode* m_first;
        ListNode* m_last;
        int m_size;

        HMQueue() {
            m_size = 0;
            m_first = nullptr;
            m_last = nullptr;
        }

        void push(int item) {
            ListNode *node = new ListNode(item);
            if (m_last == nullptr) {
                m_first = node;
                m_last = node;
            } else {
                m_last->next = node;
                m_last = node;
            }
        }

        void pop() {
            if (m_first == nullptr) {
                return;
            } else if (m_first == m_last) {
                m_first = nullptr;
                m_last = nullptr;
            } else {
                m_first = m_first->next;
            }
        }

        int top() {
            if (m_first == nullptr) {
                return 0;
            }
            return m_first->val;
        }

        bool isEmpty() {
            return m_first == nullptr;
        }

        int size() {
            return m_size;
        }
    };

    void Other::main_queue() {
        HMQueue queue = HMQueue();
        queue.push(1);
        queue.push(10);
        cout << "1 : " << queue.top()<< endl;
        queue.pop();
        queue.push(110);
        cout << "10 : " << queue.top() << endl;
        queue.push(112);
        cout << "10 : " << queue.top() << endl;
        queue.pop();
        cout << "110 : " << queue.top() << endl;
        queue.push(113);
        cout << "110 : " << queue.top() << endl;
        queue.pop();
        cout << "112 : " << queue.top() << endl;
        queue.pop();
        cout << "113 : " << queue.top() << endl;
        queue.pop();
        cout << "0 : " << queue.top() << endl;
        cout << "true : " << queue.isEmpty()<< endl;
        cout << "0 : " << queue.size()<< endl;
    }
}
