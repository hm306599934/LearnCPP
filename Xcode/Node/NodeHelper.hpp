//
//  NodeHelper.hpp
//  Xcode
//
//  Created by Jimmy on 2019/10/25.
//  Copyright © 2019 Airactart. All rights reserved.
//

#ifndef NodeHelper_hpp
#define NodeHelper_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

namespace Jimmy {

    class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;
        Node* random;

        Node() {}

        Node(int x) : val(x), left(NULL), right(NULL), next(NULL), random(NULL) {};

        Node(int _val, Node* _next, Node* _random) {
            val = _val;
            next = _next;
            random = _random;
        }
        
        Node(int _val, Node* _left, Node* _right, Node* _next) {
            val = _val;
            left = _left;
            right = _right;
            next = _next;
        }



        /// 数组转树
        /// @param vec 数组
        static Node* generateNode(vector<int*> vec);
    };


}
#endif /* NodeHelper_hpp */
