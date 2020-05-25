//
//  TestConst.cpp
//  Xcode
//
//  Created by Jimmy on 2020/1/2.
//  Copyright © 2020 Jimmy. All rights reserved.
//
//  学习Const

#include "Header.hpp"

namespace Jimmy {

    class A
    {
    private:
        const int a; // 常对象成员，只能在初始化表赋值
    public:
        A():a(0){};
        A(int x):a(x){};
        int getValue();         // 普通成员函数
        int getValue() const;   // 常成员函数，不得修改类中b成员变量
    };

    void function()
    {
        A b;
        const A a = b;   // 常对象，只能调常成员函数
        const A *p = &a; // 常指针
        const A &q = b;  // 常引用
        //
        char hello[] = "Hello";
        char *p1 = hello;
        const char *p2 = p1;//greeting;
        char* const p3 = p1;//greeting;
        const char* const p4 = p1;//greeting;
        p1 = "1234";

        p2 = p1;

        char hi[] = "hi";
        p1 = hi;

        cout << "p1 :" << p1<<endl;
        cout << "p2 :" << p2<<endl;
        cout << "p3 :" << p3<<endl;
        cout << "p4 :" << p4<<endl;
    }

    void function2()
    {
        int a = 3;
        int aa = 33;
        int *b = &a;
        int *bb = &aa;
        const int c = 4;
        const int *d = &a;
        int* const e = b;
        a = 5;
        aa = 44;
        a = 6;
        cout << "a: " << a << endl;
        cout << "b: " << *b << endl;
        cout << "c: " << c << endl;
        cout << "d: " << *d << endl;
        cout << "e: " << *e << endl;
    }

    // 函数
    void function1(const int var);
    void function2(const char* var);
    void function3(char* const var);
    void function4(const int& var);
    // 函数返回值
    const int function5();
    const int* function6();
    int* const function7();

    void test() {
        char szIn[32] = {0};
        //int iTemp = i;
        int a= (rand() % (100-1+1))+ 1;
        snprintf(szIn, sizeof(szIn)-1, "%08X", &a);
        printf("%p",&a);
        cout << szIn << " -  "<< a<< "-"<< &a << endl;
    }
    void Test::main_testConst() {
        srand((unsigned)time(NULL));
         for (int i = 0; i< 100; i++) {
            test();
            usleep(100);
         }

//        return;
        cout << "test"<<endl;
        function2();

        vector<int> v{1,2,3,4,5};
        printVector(v);

        vector<string> v2{"1是","2大萨达","3","4","5"};
        printVector(v2);

        vector<vector<int>> board{{0,1,0},
                                  {0,0,1},
                                  {1,1,1},
                                  {0,0,0}};
        print2DVector(board);

    }
}

