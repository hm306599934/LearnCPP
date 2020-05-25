//
//  Leetcode204.cpp
//  Xcode
//
//  Created by Jimmy on 2019/11/25.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"

namespace Jimmy {

    bool countPrimesIsPrime(int n) {
        for (int i = 2; i <= sqrt(n);i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int countPrimes2(int n) {
        int res = 0;
        for (int i = 2; i < n; i++) {
            if(countPrimesIsPrime(i)) {
                res++;
            }
        }
        return res;
    }

    int countPrimes(int n) {
        int res = n > 2 ? 1 : 0;
        vector<int> vec(n+1);

        for(int i=2; i <= sqrt(n); ++i) {
            if(vec[i] == 0) {
                for(int j = i*i; j < n; j += i) {
                    vec[j] = 1;
                }
            }
        }
        for (int i=3; i<n; i+=2) {
            res += vec[i] == 0;
        }
        return res;
    }

    void Leetcode::main_204() {
        cout << "4 : " << countPrimes(10) << endl;
    }
}
