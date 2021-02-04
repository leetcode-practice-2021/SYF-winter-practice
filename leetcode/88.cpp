//
// 88. 合并两个有序数组
// Created by 师域飞 on 2021/2/2.
//

#include "vector"

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        for (int i = 0; i <= nums1.size()-m; ++i) {
            nums1.pop_back();
        }
        for (int j = 0; j < n; ++j) {
            nums1.push_back(nums2[j]);
        }
        sort(nums1.begin(),nums1.end());
    }
};