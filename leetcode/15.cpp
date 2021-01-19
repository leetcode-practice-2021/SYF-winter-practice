//
// 15 三数之和
// Created by 师域飞 on 2021/1/19.
//
#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size()-2; ++i) {
            for (int j = i+1; j < nums.size()-1; ++j) {
                if (i==j)
                    continue;
                for (int k = j+1; k < nums.size(); ++k) {
                    if (k==j)
                        continue;
                    if (k+i+j==0){
                        temp.push_back(i);
                        temp.push_back(j);
                        temp.push_back(k);
                        result.push_back(temp);
                    }
                }
            }
        }
        return result;
    }
};

/*
 * ANSWER
 * vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
 */