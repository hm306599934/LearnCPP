//
//  Leetcode207.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/25.
//  Copyright © 2019 Airactart. All rights reserved.
//
// 给一个数n是课程号，需要完成0到n-1的课程
// 给定一个二维数组，分别是课程和需求先完成的课程，可能有课程冲突[0,1],[1,0]
// 判断是否可以完成所有课程
#include "Header.hpp"

namespace Jimmy {

    // 两个set，一个需要完成的课程，一个装已经完成的课程
    // DFS
    bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> m_vec(numCourses,1); //0表示未完成课程
        unordered_map<int,unordered_set<int>> m_map; //前置课程
        for (vector<int> vec : prerequisites) {
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


    // BFS  逆向思维
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int doneCourse = 0;
        unordered_map<int,vector<int>> m_map;
        vector<int> m_vec(numCourses,0);
        for (vector<int> vec : prerequisites) {
            m_map[vec[1]].push_back(vec[0]);
            m_vec[vec[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses;i++) {
            if (m_vec[i] == 0) {
                q.push(i);
                doneCourse++;
            }
        }

        while (!q.empty()) {
            if (doneCourse == numCourses) return true;
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

    // 完成课程,prerequisites里面第一个元素是课程, 其他元素是完成该课程需要先完成其他的课程
    // 判断是否可以完成课程, [[0,1],[1,0]]就无法完成课程
    void Leetcode::main_207() {
        vector<vector<int>> vc{{1,0}};
        cout <<"1 : " <<canFinish(2, vc) << endl;
        vector<vector<int>> vb{{0,1},{1,2},{0,3},{3,0}};
        cout <<"0 : " <<canFinish(4, vb) << endl;
        vector<vector<int>> va{{1,2},{2,3},{2,4},{3,4},{4,5},{5,6},{6,7}};
        cout <<"1 : " <<canFinish(10, va) << endl;
        vector<vector<int>> v9{{1,0},{2,6},{1,7},{6,4},{7,0},{0,5}};
        cout <<"1 : " <<canFinish(8, v9) << endl;
        vector<vector<int>> v8{{2,0},{1,0},{3,1},{3,2},{1,3}};
        cout <<"0 : " <<canFinish(4, v8) << endl;
        vector<vector<int>> v7{{1,0},{3,1},{3,2},{1,3}};
        cout <<"0 : " <<canFinish(4, v7) << endl;
        vector<vector<int>> v6{{1,0},{2,1}};
        cout <<"1 : " <<canFinish(3, v6) << endl;
        vector<vector<int>> v5{{0,1},{0,2},{1,0}};
        cout <<"0 : " <<canFinish(3, v5) << endl;
        vector<vector<int>> v4{{0,1},{3,1},{1,3},{3,2}};
        cout <<"0 : " <<canFinish(4, v4) << endl;
        vector<vector<int>> v1{{1,2},{2,3},{3,4},{4,1}};
        cout <<"0 : " <<canFinish(5, v1) << endl;
        vector<vector<int>> v2{{1,0}};
        cout <<"1 : " <<canFinish(2, v2) << endl;
        vector<vector<int>> v3{{1,0},{0,1}};
        cout <<"0 : " <<canFinish(2, v3) << endl;
    }
}
