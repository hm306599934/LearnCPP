//
//  Leetcode150.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/7.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    bool isOperator(string str) {
        if (str == "+" || str == "-" ||
            str == "*" || str == "/" ) {
            return true;
        }
        return false;
    }

    int doOperator(int a, int b, string op) {
        if (op == "+") {
            return a+b;
        } else if (op == "-") {
            return a-b;
        } else if (op == "*") {
            return a*b;
        } else if (op == "/") {
            return a/b;
        }
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string str : tokens) {
            if (isOperator(str)) {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int res = doOperator(a, b, str);
                s.push(res);
            } else {
                int val = stoi(str);
                s.push(val);
            }
        }
        return s.top();
    }

    void Leetcode::main_150() {
        vector<string> vec1{"2", "1", "+", "3", "*"};
        cout << evalRPN(vec1) << endl;

        vector<string> vec2{"4", "13", "5", "/", "+"};
        cout << evalRPN(vec2) << endl;

        vector<string> vec3{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
        cout << evalRPN(vec3) << endl;
    }
}
