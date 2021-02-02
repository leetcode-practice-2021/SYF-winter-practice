//
// 724. 寻找数组的中心索引
// Created by 师域飞 on 2021/1/28.
//

#include "vector"
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum=0,rightsum=0;
        int i=0,j=nums.size()-1;
        while (true){
            if (i==j)
                return leftsum==rightsum?i:-1;
            leftsum+=nums[i];
            rightsum+=nums[j];
            if (leftsum<rightsum)
                i++;
            else if (leftsum>rightsum)
                j--;
            else
                if (i==j)
                    return i;
        }
    }
};


/**
 * class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * sum + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};
 */
