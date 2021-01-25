//
// 62 不同路径
// Created by 师域飞 on 2021/1/25.
//

class Solution {
public:
    int uniquePaths(int m, int n) {
        //dp(i,j)=dp(i-1,j)+dp(j-1,i)+2
        int num[m][n];
        num[0][0] = 0;
        if (m == 1 && n == 1)
            return 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                if (i == 0 && j != 0)
                    num[i][j] = 1;
                else if (j == 0 && i != 0)
                    num[i][j] = 1;
                else
                    num[i][j] = num[i - 1][j] + num[i][j - 1];
            }
        }
        return num[m - 1][n - 1];
    }
};
/**
 * answer1
 * class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            f[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            f[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};
 */

/**
 * answer2
 * class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }
};

 */