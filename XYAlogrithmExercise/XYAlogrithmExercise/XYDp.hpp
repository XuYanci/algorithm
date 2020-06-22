//
//  XYDp.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2020/1/2.
//  Copyright © 2020 Yanci. All rights reserved.
//

#ifndef XYDp_hpp
#define XYDp_hpp

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/// 动态规划
class XYdp {
public:
    /// 简单背包问题
    int w[5] = { 0 , 2 , 3 , 4 , 5 };            //商品的体积2、3、4、5
    int v[5] = { 0 , 3 , 4 , 5 , 6 };            //商品的价值3、4、5、6
    int bagV = 8;                                //背包大小
    int dp[5][9] = { { 0 } };                    //动态规划表
    int item[5];                                 //最优解情况
    
    void findMax() {                    //动态规划
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= bagV; j++) {
                if (j < w[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    
    void findWhat(int i, int j) {                //最优解情况
        if (i >= 0) {
            if (dp[i][j] == dp[i - 1][j]) {
                item[i] = 0;
                findWhat(i - 1, j);
            }
            else if (j - w[i] >= 0 && dp[i][j] == dp[i - 1][j - w[i]] + v[i]) {
                item[i] = 1;
                findWhat(i - 1, j - w[i]);
            }
        }
    }
    
    void print() {
        for (int i = 0; i < 5; i++) {            //动态规划表输出
            for (int j = 0; j < 9; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        
        for (int i = 0; i < 5; i++)            //最优解输出
            cout << item[i] << ' ';
        cout << endl;
    }
    
    /// 背包问题1
    int knapsack(vector<int> weight,int n,int w) {
        return 0;
    }
    
    /// 背包问题2
    int knapsack2(vector<int>items,int n ,int w) {
        return 0;
    }
    
    
    void minDistBT(int i,int j,int dist,vector<vector<int>> w,int n)  {
        
    }
    
    
    int main()
    {
        findMax();
        findWhat(4, 8);
        print();
        return 0;
    }
    
};
#endif /* XYDp_hpp */
