//
// 474 1和0
// Created by 师域飞 on 2021/1/24.
//

/**
 * 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
 */
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int maxnum;
        int numZero=0,numOne=0;
        int left1=m,left2=n;
        for (int i = 0; i < strs.size(); ++i){
            int temp=0;
            numZero=count(strs[i].begin(),strs[i].end(),'0');
            numOne=count(strs[i].begin(),strs[i].end(),'1');
            left1=m-numZero;
            left2=n-numOne;
            if (left1<0||left2<0){
                maxnum=max(maxnum,temp);
            }
            else
                temp++;
            for (int j = 0; j < strs.size(); ++j) {
                if(i==j)
                    continue;
                numZero=count(strs[i].begin(),strs[i].end(),'0');
                numOne=count(strs[i].begin(),strs[i].end(),'1');
                left1=m-numZero;
                left2=n-numOne;
                if (left1<0||left2<0){
                    maxnum=max(maxnum,temp);
                }
                else
                    temp++;
            }
        }
        return maxnum;
    }
};