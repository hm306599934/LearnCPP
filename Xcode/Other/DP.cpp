//
//  DynamicProgramming.cpp
//  Xcode
//
//  Created by Jimmy on 2019/10/12.
//  Copyright © 2019 Airactart. All rights reserved.
//

#include "Header.hpp"
#include "Helper.hpp"
using namespace std;

namespace Jimmy {

    // 座位问题
    // n个人排成一排, 有男生和女生, 女生左右至少有一个女生, 求有多少种排法
    int seats(int n) {
        vector<vector<int>> dp(n+1, vector<int>(2 ,0));
        dp[1][0] = 1;
        dp[2][0] = 1;
        dp[2][1] = 1;

        for (int i = 3;i <= n; i++) {
            // 最后为男生, 男生前面是男生还是女生都可以
            dp[i][0] = dp[i-1][0] + dp[i-1][1];
            // 最后为女生, 女生全面必须为女生, 倒数第二个女生前面可以为男生
            dp[i][1] = dp[i-2][0] + dp[i-1][1];
        }

        return dp[n][0] + dp[n][1];
    }

    // 邮票问题
    // 有若干邮票，要求从中选取最少的邮票数凑成定值。
    // 如1,3,3,3,4五张邮票，要求凑成10，则最少使用3张邮票：3分、3分、4分。
    int stamps(int num, vector<int> &vec) {
        // num是需要凑的总额, vec是给定的邮票
        int count = (int)vec.size();
        // 对应i值需要多少张邮票
        vector<int> dp(num+1, 1000);
        dp[0] = 0;
        for (int i = 0; i < count; i++) {
            // 从第1张票开始加
            for (int j = num; j >= vec[i] ; j--) {
                // 选则dp[j-vec[i]]+1, 不选则dp[j]
                dp[j] = min(dp[j], dp[j-vec[i]] + 1);
            }

        }

        return dp[num];
    }

    // 分水果问题
    // 有若干重量不等水果, 划分为2份水果, 求两份水果最小差值
    int fruit(vector<int> vec) {
        int num = 0;
        for(int i = 0;i < vec.size();i++) {
            num += vec[i];
        }
        // 计算出最接近总量中间值的重量即可求出差值
        int half = num / 2;
        // num / 2舍去部分小数, 所以num / 2 + 1
        vector<int> dp(num / 2 + 1, 0);

        for (int i = 0;i < vec.size(); i++) {
            for (int j = half; j >= vec[i]; j--) {
                // 不选取该水果为dp[j], 选取该水果为dp[j-vec[i]]+vec[i]
                dp[j] = max(dp[j], dp[j-vec[i]] + vec[i]);
            }
        }
        // 因为除以2舍去部分小数, dp[half]一定小于num - dp[half]
        return num - 2 * dp[half];
    }

    // 两船载物问题
    // 有两个船和若干货物, 每个船可以载一定重量货物, 判断这两艘船是否可以装载这些货物
    // 解析: 尽量将小船装满, 然后比较剩下的货物能否装满大船
    bool boat(int a,int b, vector<int> vec) {
        int num = 0;
        for(int i = 0;i < vec.size();i++) {
               num += vec[i];
        }
        int c = a+ b;
        a = min(a, b);
        b = c - a;
        vector<int> dp(a+1, 0);

        for (int i = 0;i < vec.size(); i++) {
            for (int j = a; j >= vec[i]; j--) {
                dp[j] = max(dp[j], dp[j-vec[i]]+vec[i]);
            }
        }

        return num - dp[a] < b;
    }

    int jobPlanCmp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
    // 项目安排
    // 有多个项目可以做, 每个项目有开始时间/结束时间/报酬, 一次只能做一个项目, 如何获取最大报酬
    // 解析: 根据前i个项目规划最大报酬
    int jobPlan(vector<vector<int>> &jobs) {
        int n = (int)jobs.size();
        // 按项目开始时间排序
        sort(jobs.begin(), jobs.end(), jobPlanCmp);

        vector<int> dp(n + 1, 0);
        // dp[i]表示前i个项目的最大报酬
        dp[1] = jobs[1][2];
        int j = 0;
        for(int i = 1;i <= n; i++) {
            for (j = i - 1; j >= 1; j--) {
                if (jobs[j-1][1] <= jobs[i-1][0]) {
                    break;
                }
            }
            dp[i] = max(dp[j] + jobs[i-1][2], dp[i-1]);
        }

        return dp[n];
    }

    // 拦截导弹问题
    // 有一批高度不一样的导弹, 一次可以拦截多个导弹,拦截导弹的高度只能递减, 一次最多拦截多少导弹
    // 解析: 根据前i个导弹规划最多拦截数
    int missile(vector<int> vec) {
        int n = (int)vec.size();
        // 前i个导弹最多拦截多少
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        int res = 1;
        for (int i = 2; i <= n; i++) {
            int ii = i - 1; // 当前导弹序号
            for (int jj = 0; jj < ii; jj++) {
                if (vec[jj] >= vec[ii] && dp[jj+1] >= dp[i]) {
                    dp[i] = dp[jj+1] + 1;
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }

    // 最大递增子序列
    // 给定一个数组, 输出最大递增子序列个数
    int subSeriel(vector<int> vec) {
        int n = (int)vec.size();
        vector<int> dp(n+1, 1);

        vector<vector<int>> dpp(n+1, vector<int>(n+1, 0));

        dp[0] = 0;
        dpp[1][0] = vec[0];
        for (int i = 2; i <= n; i++) {
            int ii = i-1;

            int k = -1;
            for (int jj = 0;jj < ii;jj++) {
                int j = jj + 1;
                if (vec[ii] > vec[jj] && dp[j] >= dp[i]) {
                    dp[i] = dp[j] + 1;
                    k = j;
                }
            }

            if (dp[i] == 1){
                dpp[i][0] = vec[ii];
            } else {
                dpp[i] = dpp[k];
                dpp[i][dp[i]-1] = vec[ii];
            }
        }

        return dp[n];
    }

    // 出入栈问题
    // 给定一个数字, 表示操作次数, 输出一共有多少种操作序列
    int stack(int n) {
        if(n % 2 == 1) return 0;
        // i个操作的序列数
        vector<vector<int>> dp(n/2 + 1, vector<int>(n/2+1,0));
        for (int i = 0; i < n/2 + 1; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n / 2; i++) {
            for (int j = 1; j <= i; j++) {
                if (i == j) {
                    dp[i][j] = dp[i][j-1];
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[n/2][n/2];
    }

    void Other::main_dp() {

//        vector<int> vec{1, 3, 3 ,3, 4};
//        cout << stamps(10, vec) <<endl;


        cout << stack(10) <<endl;

    }
}

