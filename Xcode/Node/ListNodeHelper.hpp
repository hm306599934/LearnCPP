//
//  ListNodeHelper.hpp
//  Xcode
//
//  Created by Jimmy on 2019/10/28.
//  Copyright © 2019 Airactart. All rights reserved.
//

#ifndef ListNodeHelper_hpp
#define ListNodeHelper_hpp

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

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    /// 数组转树
    /// @param vec 数组
    ListNode* generateListNode(vector<int> vec);


}
#endif /* ListNodeHelper_hpp */
