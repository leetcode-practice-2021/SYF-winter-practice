//
// 121 买卖股票的最佳时间
// Created by 师域飞 on 2021/1/24.
//

/**
 * 给定一个数组 prices ，它的第i 个元素prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

 */
#include "vector"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int size=prices.size();
        for (int i = 0; i < size-1; ++i) {
            for (int j = i+1; j < size; ++j) {
                profit = max(profit, prices[j] - prices[i]);
            }

        }
        return  profit;
    }
};

/**
* answer 动态规划
 * class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};
*/