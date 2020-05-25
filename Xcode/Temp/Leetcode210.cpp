//
//  Leetcode210.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/25.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> m_map;
        vector<int> m_vec(numCourses,0);
        int doneCourse = 0;
        for (vector<int> vec : prerequisites) {
            m_map[vec[1]].push_back(vec[0]);
            m_vec[vec[0]]++;
        }
        queue<int> q;
        vector<int> res;
        for (int i = 0; i < numCourses; i++) {
            if (m_vec[i] == 0) {
                q.push(i);
                res.push_back(i);
                doneCourse++;
            }
        }
        while (!q.empty()) {
            if (doneCourse == numCourses) {
                return res;
            }
            int top = q.front();
            q.pop();
            vector<int> courses = m_map[top];
            for (int course : courses) {
                m_vec[course]--;
                if (m_vec[course] == 0) {
                    doneCourse++;
                    q.push(course);
                    res.push_back(course);
                }
            }
        }

        return vector<int>();
    }

    void Leetcode::main_210() {
        vector<vector<int>> ve{{1,0}};
        vector<int> r_ve = findOrder(2, ve);
        vector<vector<int>> vd{{1,0},{2,0},{3,1},{3,2}};
        vector<int> r_vd = findOrder(4, vd);

//        vector<vector<int>> vc{{1,0}};
//        vector<int> r_vc = findOrder(2, vc);
//
//        vector<vector<int>> vb{{0,1},{1,2},{0,3},{3,0}};
//        vector<int> r_vb = findOrder(4, vb);
        
//        vector<vector<int>> va{{1,2},{2,3},{2,4},{3,4},{4,5},{5,6},{6,7}};
//        cout <<"1 : " <<canFinish(10, va) << endl;
//        vector<vector<int>> v9{{1,0},{2,6},{1,7},{6,4},{7,0},{0,5}};
//        cout <<"1 : " <<canFinish(8, v9) << endl;
//        vector<vector<int>> v8{{2,0},{1,0},{3,1},{3,2},{1,3}};
//        cout <<"0 : " <<canFinish(4, v8) << endl;
//        vector<vector<int>> v7{{1,0},{3,1},{3,2},{1,3}};
//        cout <<"0 : " <<canFinish(4, v7) << endl;
//        vector<vector<int>> v6{{1,0},{2,1}};
//        cout <<"1 : " <<canFinish(3, v6) << endl;
//        vector<vector<int>> v5{{0,1},{0,2},{1,0}};
//        cout <<"0 : " <<canFinish(3, v5) << endl;
//        vector<vector<int>> v4{{0,1},{3,1},{1,3},{3,2}};
//        cout <<"0 : " <<canFinish(4, v4) << endl;
//        vector<vector<int>> v1{{1,2},{2,3},{3,4},{4,1}};
//        cout <<"0 : " <<canFinish(5, v1) << endl;
//        vector<vector<int>> v2{{1,0}};
//        cout <<"1 : " <<canFinish(2, v2) << endl;
//        vector<vector<int>> v3{{1,0},{0,1}};
//        cout <<"0 : " <<canFinish(2, v3) << endl;
    }
}
