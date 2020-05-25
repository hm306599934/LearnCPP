//
//  Leetcode227.cpp
//  Xcode
//
//  Created by Jimmy on 2019/12/3.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {


    int calculate2(string s) {
        stack<char> stack_op;
        stack<int> stack_num;
        bool isLastNum = false;
        for (char c : s) {
            if (c == ' ') {
                continue;
            } else if (c >= '0' && c <= '9') {
                int x = c-'0';
                if (isLastNum) {
                    int num = stack_num.top();
                    stack_num.pop();
                    if (num > 0) {
                        x += num*10;
                    } else {
                        x = num*10 - x;
                    }
                    stack_num.push(x);
                } else {
                    if (!stack_op.empty() && stack_op.top() == '-') {
                        stack_op.pop();
                        stack_op.push('+');
                        stack_num.push(x * -1);
                    } else {
                        stack_num.push(x);
                    }
                }
                isLastNum = true;
            } else {
                isLastNum = false;

                if (!stack_op.empty()) {
                    char op = stack_op.top();
                    if (op == '*' || op == '/') {
                        int a = stack_num.top();
                        stack_num.pop();
                        int b = stack_num.top();
                        stack_num.pop();
                        stack_op.pop();
                        if (op == '*') {
                            stack_num.push(a * b);
                        }else if (op == '/') {
                            stack_num.push(b / a);
                        }
                    }
                }
                if (c == '+' || c == '-') {
                    while (!stack_op.empty() && stack_num.size() > 1) {
                        int a = stack_num.top();
                        stack_num.pop();
                        int b = stack_num.top();
                        stack_num.pop();
                        char op = stack_op.top();
                        if (op == '+') {
                            stack_op.pop();
                            stack_num.push(a + b);
                        } else if (op == '-') {
                            stack_op.pop();
                            stack_num.push(b - a);
                        }
                    }
                }


                stack_op.push(c);
            }
        }

        while (!stack_op.empty() && stack_num.size() > 1) {
            int a = stack_num.top();
            stack_num.pop();
            int b = stack_num.top();
            stack_num.pop();
            char op = stack_op.top();
            stack_op.pop();
            if (op == '+') {
                stack_num.push(a + b);
            } else if (op == '-') {
                stack_num.push(b - a);
            }else if (op == '*') {
                stack_num.push(a * b);
            } else if (op == '/') {
                stack_num.push(b / a);
            }
        }
        
        return stack_num.top();
    }

    int calculate(string s) {
        int last = 0, cur = 0, sum = 0;
        char lastOP = '+';
        for (char c : s) {
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                if (lastOP == '+') {
                    sum += last;
                } else if (lastOP == '-') {
                    sum += last;
                    cur *= -1;
                } else if (lastOP == '*') {
                    cur *= last;
                } else if (lastOP == '/') {
                    cur = last / cur;
                }

                lastOP = c;
                last = cur;
                cur = 0;
            }
            if (c >= '0' && c <= '9') {
                cur = cur * 10 + c - '0';
            }
        }

        if (lastOP == '+') {
            sum += last;
        } else if (lastOP == '-') {
            sum += last;
            cur *= -1;
        } else if (lastOP == '*') {
            cur *= last;
        } else if (lastOP == '/') {
            cur = last / cur;
        }
        sum += cur;
        return sum;
    }

    void Leetcode::main_227() {
        cout << "1*2-3/4+5*6-7*8+9/10 = " << calculate("1*2-3/4+5*6-7*8+9/10") << endl;
        cout << "1-1+1 = " << calculate("1-1+1") << endl;
        cout << "0-2147483647 = " << calculate("0-2147483647") << endl;
        cout << "13+2*2 = " << calculate("13+2*2") << endl;
        cout << "3/2 = " << calculate(" 3/2 ") << endl;
        cout << "3+5 / 2 = " << calculate(" 3+5 / 2 ") << endl;
    }
}
