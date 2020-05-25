//
//  BFS.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/2.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    bool bfs1(int n, vector<vector<int>>& graph) {
        int doneCourse = 0;
        unordered_map<int,vector<int>> m_map;
        vector<int> m_vec(n,0);
        for (vector<int> vec : graph) {
            m_map[vec[1]].push_back(vec[0]);
            m_vec[vec[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < n;i++) {
            if (m_vec[i] == 0) {
                q.push(i);
                doneCourse++;
            }
        }

        while (!q.empty()) {
            if (doneCourse == n) return true;
            int top = q.front();
            q.pop();
            vector<int> preCourses = m_map[top];

            for (int preCourse : preCourses) {
                m_vec[preCourse]--;
                if (m_vec[preCourse] == 0) {
                    q.push(preCourse);
                    doneCourse++;
                }
            }
        }
        return false;
    }

    bool dfs1(int n, vector<vector<int>>& graph) {
        vector<int> m_vec(n,1); //0表示未完成课程
        unordered_map<int,unordered_set<int>> m_map; //前置课程
        for (vector<int> vec : graph) {
            if (m_vec[vec[0]] == 1) {
                m_vec[vec[0]] = 0;
            }
            if (m_map.count(vec[0]) == 0) {
                unordered_set<int> set;
                set.insert(vec[1]);
                m_map[vec[0]] = set;
            } else {
                m_map[vec[0]].insert(vec[1]);
            }
        }

        stack<int> m_stack;
        unordered_set<int> m_stackSet;
        for (int i = 0;i < m_vec.size();i++) {
            if (m_vec[i] == 1) {
                continue;
            }
            m_stack.push(i);
            m_stackSet.insert(i);
            while (!m_stack.empty()) {
                int top = m_stack.top();

                if (m_map.count(top) > 0) {
                    unordered_set<int> ss = m_map[top];
                    unordered_set<int>::iterator iter = ss.begin();
                    while (iter != ss.end()) {
                        int x = *iter;
                        if (m_vec[x] == 0) {
                            if (m_stackSet.count(x) > 0) {
                                return false;
                            }
                            m_stack.push(x);
                            m_stackSet.insert(x);
                        }
                        iter++;
                    }
                }
                if (top == m_stack.top()) {
                    break;
                }
            }

            while(!m_stack.empty()) {
                m_vec[m_stack.top()] = 1;
                m_stackSet.erase(m_stack.top());
                m_stack.pop();
            }
        }

        return true;
    }


    void Other::main_BDFS() {
        vector<vector<int>> graph{{1,2,3,4,5},{6,7,8,9},{11,12,13,14}};
        bfs1(1, graph);
        dfs1(1, graph);
    }
}
