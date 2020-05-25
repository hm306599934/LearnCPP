//
//  Stack.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/28.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    class HMStack {
        public:
        ListNode *m_first;
        int m_size;

        HMStack() {
            m_first = nullptr;
            m_size = 0;
        }

        void push(int item) {
            ListNode *node = new ListNode(item);
            node->next = m_first;
            m_first = node;
            m_size++;
        }

        void pop() {
            if (m_first != nullptr) {
                m_first = m_first->next;
                m_size--;
            }
        }

        int top() {
            return m_first->val;
        }

        int size() {
            return m_size;
        }

        bool isEmpty() {
            return m_first == nullptr;
        }
    };

    void Other::main_stack() {
        HMStack stack = HMStack();
        stack.push(1);
        stack.pop();
        stack.push(10);
        cout << "1 : " << stack.size()<< endl;
        stack.push(110);
        cout << "10 : " << stack.top() << endl;
        stack.push(112);
        stack.pop();
        cout << "10 : " << stack.top() << endl;
        stack.push(113);
        cout << "10 : " << stack.top() << endl;
        stack.pop();
        stack.pop();
        stack.pop();
        cout << "true : " << stack.isEmpty()<< endl;
        cout << "0 : " << stack.size()<< endl;
    }
}
