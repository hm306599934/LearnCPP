//
//  Leetcode679.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/19.
//  Copyright © 2019 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

//        vector<double> combine2(double a, double b) {
//            return {a / b, b / a, a + b, a - b, b - a, a * b};
//        }
//
//        bool judgePoint24(vector<int>& nums) {
//            vector<int> id ({0, 1, 2, 3});
//            do {
//                int a = nums[id[0]], b = nums[id[1]], c = nums[id[2]], d = nums[id[3]];
//                for (auto x: combine2(a, b))
//                    for (auto y: combine2(c, d))
//                        for (auto z: combine2(x, y))
//                            if (abs(z - 24) < 1e-4) {
//                                return true;
//                            }
//                for (auto x: combine2(a, b))
//                    for (auto y: combine2(c, x))
//                        for (auto z: combine2(d, y))
//                            if (abs(z - 24) < 1e-4) {
//                                return true;
//                            }
//            } while (next_permutation(id.begin(), id.end()));
//            return false;
//        }


       void isPossibleHelper(vector<int> &vec, int index,queue<string> &res) {
        if (index > 3) return;
        int size = (int)res.size();
        for (int i= 0;i < size;i++) {
            string top = res.front();
            res.pop();
            res.push(top + "+" + to_string(vec[index]));
            res.push(top + "-" + to_string(vec[index]));
            res.push(top + "*" + to_string(vec[index]));
            res.push(top + "/" + to_string(vec[index]));
        }

        isPossibleHelper(vec, index+1, res);
    }

    int calculateString(string str) {
        stack<float> m_num;
        stack<char> m_op;
        for (char c : str) {
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                m_op.push(c);
            } else {
                float b = c-'0';
                if (m_num.empty()) {
                    m_num.push(b);
                    continue;
                }
                float a = m_num.top();
                if (!m_op.empty() && m_op.top() == '*') {
                    m_num.pop();
                    m_num.push(a*b);
                } else if (!m_op.empty() && m_op.top() == '/') {
                    m_num.pop();
                    m_num.push(a/b);
                }  else {
                    m_num.push(b);
                }
            }
        }

        float res = 0;
        while (!m_op.empty() && !m_num.empty()) {
            float a = m_num.top();
            m_num.pop();
            char op = m_op.top();
            m_op.pop();
            if (op == '-') {
                a = -a;
            }
            res += a;
        }
        while (!m_num.empty()) {
            float a = m_num.top();
            m_num.pop();
            res += a;
        }

        cout << str << " = " << res<<endl;
        return res;
    }

    void swapPoint24(vector<int> &vec,int i,int j){
        int tmp = vec[i];
        vec[i] = vec[j];
        vec[j] = tmp;
    }

    bool isSwapPoint24(vector<int> &vec,int len,int index){
        for(int i=index+1;i<len;++i)
            if(vec[index]==vec[i])
                return false;
        return true;
    }


    void swapArrayPoint24(vector<int> vec,int size,int index, vector<vector<int>> &res){
        if(index == size) {
            res.push_back(vec);
            return;
        }
        else {
            for(int i=index;i<size;++i){
                if (isSwapPoint24(vec,size,index)) {
                    swapPoint24(vec,index,i);
                    swapArrayPoint24(vec,size,index+1,res);
                    swapPoint24(vec,index,i);
                }
            }
        }
    }

    //穷举所有可能
    bool judgePoint24(vector<int>& nums) {
        vector<vector<int>> ress;
        swapArrayPoint24(nums,4,0,ress);

        for (vector<int> vec : ress) {
            queue<string> res;
            res.push(to_string(vec[0]));
            isPossibleHelper(vec, 1,res);

            while (!res.empty()) {
                string ss = res.front();
                if (calculateString(ss) == 24) {
                    return true;
                }
                res.pop();
            }
        }


        return false;
    }

    // 判断24点，可以有小数
    void Leetcode::main_679() {
        vector<int> v4{1,3,2,6};
        cout << " true: " << judgePoint24(v4)<<endl;
        vector<int> v3{1,3,4,6};
        //cout << " true: " << judgePoint24(v3)<<endl;
        vector<int> v1{4,1,8,7};
        //cout << " true: " << judgePoint24(v1)<<endl;
        vector<int> v2{1,2,1,2};
        //cout << " false: " << judgePoint24(v2)<<endl;
    }
}
