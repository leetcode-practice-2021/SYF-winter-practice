//
// 300 最长递增子序列
// Created by 师域飞 on 2021/1/25.
//

/**
 * 你可以设计时间复杂度为 O(n2) 的解决方案吗？
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 */
#include "vector"
using namespace  std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int>len;
        len.push_back(1);
        for (int i = 1; i < nums.size(); ++i) {
            int maxlen=1;
            for (int j = 0; j < i; ++j) {
                if (nums[j]<nums[i])
                    maxlen=max(maxlen,len[j]+1);
            }
            len.push_back(maxlen);
        }
        sort(len.begin(),len.end());
        return len[len.size()-1];
    }
};
//dp[i]=max(dp[j])+1,其中0≤j<i且num[j]<num[i]

/**
 * answer 2
 * class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            } else {
                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
 */