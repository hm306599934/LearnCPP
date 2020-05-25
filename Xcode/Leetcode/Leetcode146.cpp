//
//  Leetcode146.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/8.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    class LRUCache {
    public:
//        unordered_map<int, pair<int, list<int>::iterator>> cache;
//        list<int> tracker;
//        int m_capacity;
//
//        void changePriority(int key) {
//            tracker.erase(cache[key].second);
//            tracker.push_back(key);
//            cache[key].second = --tracker.end();
//        }
//
//        LRUCache(int capacity) {
//            m_capacity = capacity;
//        }
//
//        int get(int key) {
//            if (!m_capacity || cache.find(key) == cache.end()) return -1;
//            changePriority(key);
//            return cache[key].first;
//        }
//
//        void put(int key, int value) {
//            if (!m_capacity) return;
//            if (cache.find(key) != cache.end()) {
//                cache[key].first = value;
//                changePriority(key);
//            } else {
//                if (tracker.size() >= m_capacity) {
//                    cache.erase(tracker.front());
//                    tracker.pop_front();
//                }
//                tracker.push_back(key);
//                cache[key].first = value;
//                cache[key].second = --tracker.end();
//            }
//        }

        int m_capacity;
        list<int> m_list;
        unordered_map<int, int> m_map;

        void changePriority(int key) {
            list<int>::iterator iter = m_list.begin();
            while(iter != m_list.end()) {
                if (*iter == key) {
                    m_list.erase(iter);
                    break;
                }
                iter++;
            }
            m_list.push_back(key);
        }

        LRUCache(int capacity) {
            m_capacity = capacity;
        }

        int get(int key) {
            if (m_map.count(key) > 0) {
                changePriority(key);
                return m_map[key];
            }

            return -1;
        }

        void put(int key, int value) {
            changePriority(key);
            if (m_list.size() > m_capacity) {
                int val = m_list.front();
                m_map.erase(val);
                m_list.erase(m_list.begin());

            }
            m_map[key] = value;
        }
    };

    void Leetcode::main_146() {
        LRUCache cache = LRUCache(2);
        cache.put(1, 1);
        cache.put(2, 2);
        int val1 = cache.get(1);
        cache.put(3, 3);
        int val2 = cache.get(2);
        cache.put(4, 4);
        int val3 = cache.get(1);
        int val4 = cache.get(3);
        int val5 = cache.get(4);

        cout << "|  1 | " << val1 << endl;
        cout << "| -1 | " << val2 << endl;
        cout << "| -1 | " << val3 << endl;
        cout << "|  3 | " << val4 << endl;
        cout << "|  4 | " << val5 << endl;

//        LRUCache cache = LRUCache(2);
//        cache.put(2, 1);
//        cache.put(1, 1);
//        cache.put(2, -3);
//        cache.put(4, 1);
//        int val1 = cache.get(1);
//        int val2 = cache.get(2);
//
//        cout << "| -1 | " << val1 << endl;
//        cout << "| -3 | " << val2 << endl;

//        LRUCache cache = LRUCache(2);
//        int val1 = cache.get(2);
//        cache.put(2, 6);
//        int val2 = cache.get(1);
//        cache.put(1, 5);
//        cache.put(1, 2);
//        int val3 = cache.get(1);
//        int val4 = cache.get(2);
//
//        cout << "| -1 | " << val1 << endl;
//        cout << "| -1 | " << val2 << endl;
//        cout << "|  2 | " << val3 << endl;
//        cout << "|  6 | " << val4 << endl;


        
    }
}
