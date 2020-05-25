//
//  TestTest.cpp
//  Xcode
//
//  Created by Jimmy on 2020/1/10.
//  Copyright © 2020 Jimmy. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    template<typename T>
    bool comp(T a, T b) {
        return a < b;
    }

    template<typename F>
    int aaa(int a, F  f)  {
        return f() + a;
    }

    class MyClass
    {
    char* _data;
    size_t _len;
    void _init_data(const char *s) {
        _data = new char[_len+1];
        memcpy(_data, s, _len);
        _data[_len] = '\0';
    }
    public:
        MyClass(const char* p) {
            cout << "默认构造函数" << endl;
            _len = strlen(p);
            _init_data(p);
        }

        MyClass(MyClass&& c) {
            cout << "move构造函数" << endl;
            _len = c._len;
            _data = c._data;
            c._len = 0;
            c._data = NULL;
        }

        MyClass(const MyClass& c) {
            cout << "copy构造函数" << endl;
            _len = c._len;
            _init_data(c._data);
        }

        MyClass& operator=(MyClass&& c) {
            cout << "move赋值" << endl;
            _len = c._len;
            _data = c._data;
            c._len = 0;
            c._data = NULL;
            return *this;
        }

        MyClass& operator=(const MyClass& c) {
            cout << "拷贝赋值" << endl;
            if (&c != this) {
                this->_len = c._len;
                this->_data = c._data;
            }

            return *this;
        }

        virtual ~MyClass(){
            if (_data) {
                free(_data);
            }
        }

    };

    void testLeftReference(MyClass& mc) {
        cout << "左值引用" << endl;
    }

    void testRightReference(MyClass&& mc) {
        cout << "右值引用" << endl;
    }

    class CA {
        int *a;

    };

    class CB:CA {
    public:
        virtual ~CB() {

        }
    };

    void Test::main_testTest() {

        CA ca = CA();
        cout << sizeof(ca) <<endl;

        CB cb = CB();
        cout << sizeof(cb) <<endl;

//        tuple<int,float> t1(1, 1.2);
//        typedef tuple<int,float> TupleType;

        //cout << tuple_size<TupleType>::value << endl;

//        typedef tuple_element<0, TupleType> T;

        //cout << sizeof(T) << endl;
        //cout << sizeof(int) << endl;

//        vector<int> vec = {1,4,2,1,4,7,3};
//        sort(vec.begin(), vec.end(), comp<int>);
//
//        vector<int> vec2 = vec;
//        sort(vec2.begin(), vec2.end(), [](int a, int b ){return a < b;});
//
//        for (auto a : vec2) {
//            cout << a << endl;
//        }
//        int a = 4;
//        cout << aaa(1, [&]()mutable{a++;return a*2;}) << endl;;
//        cout << a;
    }

}
