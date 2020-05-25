//
//  Thread_1.cpp
//  Xcode
//
//  Created by Jimmy on 2020/4/28.
//  Copyright © 2020 Jimmy. All rights reserved.
//


#include "Header.hpp"
#define NAMESPACE_NAME Threads_1

namespace NAMESPACE_NAME {

void doSomeWork()
{
    cout << "do work" << endl;
}

void f1(int a, int b) {
    cout << "n : " << a + b << endl;
}

void f2(int &a) {
    cout << ++a << endl;
}

class foo{
public:
    void bar() {
        cout << "bar" << endl;
    }
};

class baz {
public:
    void operator ()(int n) {
        cout << "baz : " << n << endl;
    }
};

void test()
{
    cout << "123" << endl;
    thread t1(f1,3, 8);
    t1.join();
    int a = 5;
    thread t2(f2, ref(a));
    //t2.join();
    cout << a << endl;
    thread t3(move(t2));
    t3.join();

    foo f;
    thread t5(&foo::bar, &f);
    t5.join();


    thread t6(baz(), 2);
    t6.join();
    this_thread::sleep_for(chrono::milliseconds(4));

}


}

using namespace NAMESPACE_NAME;
void Jimmy::Threads::main_threads_1() {

    test();
}
