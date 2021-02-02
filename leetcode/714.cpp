//
// 714. 买卖股票的最佳时机含手续费
// Created by 师域飞 on 2021/2/2.
//

#include "vector"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit=0;
        int size=prices.size();
        for (int i = 0; i < size-1; ++i) {
            for (int j = i+1; j < size; ++j) {
                profit = max(profit, prices[j] - prices[i]-fee);
            }

        }
        return  profit;
    }
};

/**
 * class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

 */