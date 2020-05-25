//
//  Sort_Merge.cpp
//  Xcode
//
//  Created by Jimmy on 2020/1/7.
//  Copyright © 2020 Jimmy. All rights reserved.
//
//  归并排序

#include "Header.hpp"


namespace Jimmy {

    // 合并两个有序数组
    static void mergeSortMerge(vector<int> &vec,int l, int r, int mid,vector<int> &temp) {
        int left = l, right = mid+1;
        int i = 0;
        while (left <= mid && right <= r) {
            if (vec[left] < vec[right]) {
                temp[i++] = vec[left++];
            } else {
                temp[i++] = vec[right++];
            }
        }

        while (left <= mid) temp[i++] = vec[left++];
        while (right <= r) temp[i++] = vec[right++];

        i = 0;
        while (l <= r) vec[l++] = temp[i++];
    }

    // temp用于合并时装临时数据, 避免生成过多临时数组, 用外面传入
    static void mergeSort(vector<int> &vec,int l, int r,vector<int> &temp) {
        if (l < r) {
            int mid = (l + r) / 2;
            mergeSort(vec, l, mid, temp);
            mergeSort(vec, mid+1, r, temp);
            mergeSortMerge(vec, l, r, mid, temp);
        }
    }
    
    // 先将数组拆分为2个,2个拆分为4个,...最后拆分为1一个
    // 让后排序, 排序完合并
    //               84571362
    //           8457        1362
    //         84    57    13    62
    //        8  4  5  7  1  3  6  2
    //         48    57    13    26
    //           4587        1236
    //               12345678
    void Sort::main_merge() {
        vector<int> v1{4,12,2,6,3,18,2,19,23,13,8,6,7,16,5,12,4};
        vector<int> v2{9,6,7,16,5,12,4};
        vector<int> v3 = getVectorInt(20);
        vector<int> v4{8,4,5,7,1,3,6,2};

        vector<int> v = v1;
        printVector(v);
        vector<int> temp(v.size());
        mergeSort(v, 0, (int)v.size()-1,temp);
        printVector(v);
    }

}
