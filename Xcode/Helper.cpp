//
//  Helper.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/10.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Helper.hpp"


namespace Jimmy {

    void printListNode(ListNode *head) {
        cout <<endl<< "[";
        if (head != nullptr) {
            cout << head->val;
            head = head->next;
            while (head != nullptr) {
                cout <<" -> " << head->val;
                head = head->next;
            }
        }
        cout << "]" << endl;
    }

    int getRandomNumber(int min, int max) {
        srand((unsigned)time(NULL));
        int res = (rand() % (max-min+1))+ min;
        return res;
    }

    vector<int> getVectorInt(int size) {
        srand((unsigned)time(NULL));
        int res = (rand() % 100);
        if (size == -1) size = res;
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            int a = (rand() % 100);
            vec.push_back(a);
        }
        return vec;
    }

}

