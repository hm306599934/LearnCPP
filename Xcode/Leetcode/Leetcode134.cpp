//
//  Leetcode134.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/30.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    // flags[i][j] 记录i到j点剩余的汽油
    bool canCompleteCircuitRecrution(vector<int>& gas, vector<int>& cost, int index, vector<vector<int>> &flags) {


        for (int i = 0;i < cost.size();i++) {

        }

        if (canCompleteCircuitRecrution(gas, cost, index + 1, flags)) {
            return true;
        }

        cout << "123" << endl;
        return false;
    }

    // 递归
    int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
        int n = (int)cost.size();
        vector<int> dp;
        vector<vector<int>> flags(n, vector<int>(n, 0)); //flags[i][j] 记录到x点需要汽油
        //canCompleteCircuitRecrution(gas, cost, 0, flags);


        vector<int> left(n, 0);
        for (int i = 0;i < cost.size();i++) {
            left[i] = gas[i] - cost[i];
        }

        for (int i = 0;i < left.size();i++) {
            if (left[i] < 0) continue;
            int num = left[i];
            for (int j = 1;j <= left.size();j++) {
                int index = (i + j) % left.size();
                num += left[index];
                if (num < 0) {
                    break;
                }

            }
            if (num > 0) {
                return i;
            }
        }
        return -1;
    }

    // 循环
    int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {

        vector<int> cache;
        int num = 0;
        for (int i = 0;i < gas.size();i++) {
            num = gas[i] - cost[i];
            if (num < 0) continue;
            for (int j = 1;j <= gas.size();j++) {
                int index = (i + j) % gas.size();
                num += gas[index] - cost[index];
                if (num < 0) {
                    break;
                }
            }
            if (num >= 0) {
                return i;
            }
        }
        return -1;
    }

    // dp
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, start = 0, min = INT_MAX;
        for(int i = 0; i < gas.size(); i++){
            sum += gas[i]-cost[i];
            if(sum < min){
                min = sum;
                start = i;
            }
        }

        return sum < 0 ? - 1 : (start+1) % gas.size();
    }

    // dp
    // 递归
    // 双指针
    void Leetcode::main_134() {
        vector<int> gas1{1,2,3,4,5};
        vector<int> cost1{3,4,5,1,2};
        cout << canCompleteCircuit(gas1, cost1) << " | 3 "<<endl;

        vector<int> gas2{2,3,4};
        vector<int> cost2{3,4,3};
        cout << canCompleteCircuit(gas2, cost2) << " | -1 "<<endl;

        vector<int> gas3{2};
        vector<int> cost3{2};
        cout << canCompleteCircuit(gas3, cost3) << " | 0 "<<endl;
    }
}
