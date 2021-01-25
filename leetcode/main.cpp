#include <iostream>
#include <stdio.h>
#include "vector"
#include "string"

using namespace std;

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

int main() {
    std::cout << "Hello, World!" << std::endl;
    int x[8] = {10,9,2,5,3,7,101,18};
    vector<int> n(x, x + 8);
    cout << lengthOfLIS(n);
    return 0;
}
