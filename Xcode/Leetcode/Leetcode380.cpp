//
//  Leetcode380.cpp
//  Xcode
//
//  Created by Jimmy on 2020/1/4.
//  Copyright © 2020 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    class RandomizedSet2 {
    private:
        unordered_set<int> m_set;
    public:
        /** Initialize your data structure here. */
        RandomizedSet2() {
            srand((unsigned)time(NULL));
        }

        /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
        bool insert(int val) {
            if (m_set.count(val) > 0) {
                return false;
            }
            m_set.insert(val);
            return true;
        }

        /** Removes a value from the set. Returns true if the set contained the specified element. */
        bool remove(int val) {
            if (m_set.count(val) == 0) {
                return false;
            }
            m_set.erase(val);
            return true;
        }

        /** Get a random element from the set. */
        int getRandom() {
            if (m_set.empty()) return 0;
            vector<int> vec(m_set.begin(),m_set.end());
            int res = (rand() % (vec.size()));
            return vec[res];
        }
    };

    class RandomizedSet {
    private:
        unordered_map<int,int> m_map;
        vector<int> m_vec;
    public:
        /** Initialize your data structure here. */
        RandomizedSet() {
            srand((unsigned)time(NULL));
        }

        /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
        bool insert(int val) {
            if (m_map.count(val) > 0) {
                return false;
            }
            m_vec.push_back(val);
            m_map[val] = (int)m_vec.size()-1;
            return true;
        }

        /** Removes a value from the set. Returns true if the set contained the specified element. */
        bool remove(int val) {
            if (m_map.count(val) == 0) {
                return false;
            }
            int index = m_map[val];
            int last = (int)m_vec.size()-1;
            int temp = m_vec[m_vec.size()-1];
            m_vec[last] = m_vec[index];
            m_vec[index] = temp;
            m_map[temp] = index;
            m_map[val] = last;
            m_vec.pop_back();
            m_map.erase(val);
            return true;
        }

        /** Get a random element from the set. */
        int getRandom() {
            int res = (rand() % (m_vec.size()));
            return m_vec[res];
        }
    };

    // 设计一个数据结构,实现插入,删除,取随机值,所有操作时间复杂度都是O(1)
    void Leetcode::main_380() {

        RandomizedSet* obj = new RandomizedSet();
        cout << "true: " << obj->insert(0)<<endl;
        cout << "true: " << obj->insert(1)<<endl;
        cout << "true: " << obj->remove(0)<<endl;
        cout << "false: " << obj->insert(2)<<endl;
        cout << "true: " << obj->remove(1)<<endl;

        cout << "random: " << obj->getRandom()<<endl;
        cout << "random: " << obj->getRandom()<<endl;
        cout << "random: " << obj->getRandom()<<endl;
        cout << "random: " << obj->getRandom()<<endl;
        cout << "random: " << obj->getRandom()<<endl;
        cout << "random: " << obj->getRandom()<<endl;
        cout << "random: " << obj->getRandom()<<endl;
        cout << "random: " << obj->getRandom()<<endl;
    }
}
