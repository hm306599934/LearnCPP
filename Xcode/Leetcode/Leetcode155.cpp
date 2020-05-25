//
//  Leetcode155.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/4.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

class MinStack {
public:

    MinStack() {

    }
    void push(int x) {
        m_stack.push_back(x);
        if (m_min.empty()) {
            m_min.push_back(x);
        } else {
            if (x < m_min.back()) {
                m_min.push_back(x);
            } else {
                m_min.push_back(m_min.back());
            }
        }
    }
    void pop() {
        m_stack.pop_back();
        m_min.pop_back();
    }
    int top() {
        return m_stack.back();
    }

    int getMin() {
        return m_min.back();
    }

private:
    vector<int> m_stack;
    vector<int> m_min;
};


    void Leetcode::main_155() {
        MinStack *obj = new MinStack();
        obj->push(5);
        obj->push(8);
        obj->pop();
        obj->push(7);
        obj->push(9);
        obj->pop();
        cout << "top: " << obj->top() << " min: " << obj->getMin() << endl;
        obj->pop();
        cout << "top: " << obj->top() << " min: " << obj->getMin() << endl;
        obj->push(1);
        cout << "top: " << obj->top() << " min: " << obj->getMin() << endl;
        obj->push(4);
        int a1 = obj->top();
        obj->pop();
        int a2 = obj->top();
        int a3 = obj->getMin();
        cout << "a1: " << a1 << " a2: " << a2 << " a3: " << a3 << endl;

    }
}
