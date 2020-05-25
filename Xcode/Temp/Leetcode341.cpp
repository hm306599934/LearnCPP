//
//  Leetcode_341.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/23.
//  Copyright © 2019 Jimmy. All rights reserved.
//
//  实现一个迭代器读取嵌套数组

#include "Header.hpp"

namespace Jimmy {

    class NestedInteger {
    public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
    };

    class NestedIterator {
    public:
        NestedIterator(vector<NestedInteger>& nestedList) : nested_list(nestedList), cur_iter(nullptr), idx(0) {
        }

        int next() {
            if (cur_iter == nullptr)
                return nested_list[idx++].getInteger();
            else
                return cur_iter->next();
        }

        bool hasNext() {
            if (cur_iter != nullptr && !cur_iter->hasNext()) {
                delete cur_iter;
                cur_iter = nullptr;
            }

            while (idx < nested_list.size() && cur_iter == nullptr && !nested_list[idx].isInteger()) {
                //cur_iter = new NestedIterator(nested_list[idx++].getList());

                if (!cur_iter->hasNext()) {
                    delete cur_iter;
                    cur_iter = nullptr;
                }
            }

            return idx < nested_list.size() || cur_iter != nullptr;
        }

    private:
        vector<NestedInteger>& nested_list;
        NestedIterator* cur_iter;
        int idx;
    };

    void Leetcode::main_341() {
        vector<NestedInteger> i;
        NestedIterator iter(i);
        while(iter.hasNext()) {
            cout << iter.next();
        };
    }
}

