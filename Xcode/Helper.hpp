//
//  Helper.hpp
//  Xcode
//
//  Created by Jimmy on 2019/10/10.
//  Copyright © 2019 Airactart. All rights reserved.
//

#ifndef Helper_hpp
#define Helper_hpp

#import "Header.hpp"
#import "ListNodeHelper.hpp"

using namespace std;

namespace Jimmy {

    /// 打印链表
    /// @param head 链表头
    void printListNode(ListNode *head);

    /// 获取随机数
    /// @param min 最小值
    /// @param max 最大值
    int getRandomNumber(int min, int max);

    /// 获取指定长度的整型数组
    /// @param size 数组长度, -1表示随机长度,最大99
    vector<int> getVectorInt(int size = -1);

    /// 打印数组
    /// @param vec 数组
    template<typename T>
    void printVector(vector<T>& vec) {
        cout <<endl<< "[";
        for (T iter : vec) {
            cout << iter << " , ";
        }
        cout << "]" << endl;
    };
    
    /// 打印二维数组
    /// @param vec 二维数组
    template<typename T>
void print2DVector(vector<vector<T> >& vec) {
        cout <<endl<< "-------------" << endl;
        for (vector<T> rows : vec) {
            for (T c : rows) {
                cout << c << " ";
            }
            cout << endl;
        }
        cout << "-------------" << endl;
    }

    /// 交换数组中的位置
    template<typename T>
    void swapVector(vector<T> &vec, int i, int j) {
        T temp =  vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }

}

#endif /* Helper_hpp */
