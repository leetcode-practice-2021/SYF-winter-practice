//
// 978 最长湍流子数组
// Created by 师域飞 on 2021/1/25.
//

/**
 * 当 A的子数组A[i], A[i+1], ..., A[j]满足下列条件时，我们称其为湍流子数组：
 * 若i <= k < j，当 k为奇数时，A[k] > A[k+1]，且当 k 为偶数时，A[k] < A[k+1]；
 * 或 若i <= k < j，当 k 为偶数时，A[k] > A[k+1]，且当 k为奇数时，A[k] < A[k+1]。
 * 也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。
 * 返回 A 的最大湍流子数组的长度。
 */
#include "vector"

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int> &arr) {
        //dp(k)=max(dp(k+1))+1
        vector<int> len;
        len.push_back(1);
        for (int i = 1; i < arr.size(); ++i) {
            int maxlen = 1;
            if (i % 2 == 0 && arr[i] > arr[i - 1])
                maxlen = max(len[i-1] + 1, maxlen);
            if (i % 2 == 1 && arr[i] < arr[i - 1])
                maxlen = max(len[i-1] + 1, maxlen);
            len.push_back(maxlen);
        }
        sort(len.begin(),len.end());

        vector<int> len2;
        len2.push_back(1);
        for (int i = 1; i < arr.size(); ++i) {
            int maxlen = 1;
            if (i % 2 == 0 && arr[i] > arr[i - 1])
                maxlen = max(len2[i-1] + 1, maxlen);
            if (i % 2 == 1 && arr[i] < arr[i - 1])
                maxlen = max(len2[i-1] + 1, maxlen);
            len2.push_back(maxlen);
        }
        sort(len2.begin(),len2.end());
        return max(len[len.size()-1],len2[len2.size()-1]);
    }
};

/**
 * answer 滑动窗口
 * class Solution {
    public int maxTurbulenceSize(int[] A) {
        int N = A.length;
        int ans = 1;
        int anchor = 0;

        for (int i = 1; i < N; ++i) {
            int c = Integer.compare(A[i-1], A[i]);
            if (i == N-1 || c * Integer.compare(A[i], A[i+1]) != -1) {
                if (c != 0) ans = Math.max(ans, i - anchor + 1);
                anchor = i;
            }
        }

        return ans;
    }
}
 */