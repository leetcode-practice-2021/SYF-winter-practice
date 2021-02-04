//
// 33. 搜索旋转排序数组
// Created by 师域飞 on 2021/2/3.
//

#include "vector"

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index=-1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]==target)
                index==i;
        }
        if (index==-1)
            return index;
        for (int i = 1; i < nums.size(); ++i) {
            if (i<index&&nums[i]<nums[i-1])
                return -1;
            else if (i>index&&nums[i]<nums[i-1])
                return -1;
        }
        return index;
    }
};

/**
 * 二分查找
 * class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
 */