//
//  TestContainer.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/17.
//  Copyright © 2019 Airactart. All rights reserved.
//
//  容器

#include "Header.hpp"

namespace Jimmy {

    void Test::main_testContainer() {

        //char *aa[] = {"abc", "def", "fgh", "jkhf"};

        vector<string> vec{"abc", "def", "fgh", "jkhf"};

        vector<string>::reverse_iterator iter = vec.rbegin();

        while (iter != vec.rend()) {
            cout << *iter <<endl;
            iter++;
        }

        pair<string, int> a("a", 1);
        pair<string, int> b("b", 2);
        pair<string, int> c("c", 3);

        map<string,int> m;
        m.insert(a);
        cout << m.begin()->first << " | " << m.begin()->second ;

        cout << "1234" << endl;

    }
  
}
