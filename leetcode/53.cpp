//
// 53 最大子序和
// Created by 师域飞 on 2021/1/25.
//
#include "vector"
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //current_sum = max(x, x + current_sum)
        //vector<int>cursum;
        //cursum.push_back(nums[0]);
        int currentsum=nums[0];
        int maxsum=nums[0];//降低时间复杂度

        for (int i = 1; i < nums.size(); ++i) {
            currentsum=max(nums[i], nums[i] + currentsum);
            maxsum=max(maxsum, currentsum);
            //cursum.push_back(currentsum);
        }
        //sort(cursum.begin(),cursum.end());
        return maxsum;

    }
};

/**
 * answer 1 动态规划 空间复杂度降至O(1)
 * class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};
 */

/**
 * answer2 分而治之
 * class Solution {
public:
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    };

    Status get(vector<int> &a, int l, int r) {
        if (l == r) {
            return (Status) {a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};
 */