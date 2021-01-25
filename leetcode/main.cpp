#include <iostream>
#include <stdio.h>
#include "vector"
#include "string"

using namespace std;

int maxTurbulenceSize(vector<int> &arr) {
    //dp(k)=max(dp(k+1))+1
    vector<int> len;
    len.push_back(1);
    for (int i = 1; i < arr.size(); ++i) {
        int maxlen = 1;
        if (i % 2 == 0 && arr[i] > arr[i - 1])
            maxlen = max(len[i - 1] + 1, maxlen);
        if (i % 2 == 1 && arr[i] < arr[i - 1])
            maxlen = max(len[i - 1] + 1, maxlen);
        len.push_back(maxlen);
    }
    sort(len.begin(), len.end());

    vector<int> len2;
    len2.push_back(1);
    for (int i = 1; i < arr.size(); ++i) {
        int maxlen = 1;
        if (i % 2 == 0 && arr[i] < arr[i - 1])
            maxlen = max(len2[i - 1] + 1, maxlen);
        if (i % 2 == 1 && arr[i] > arr[i - 1])
            maxlen = max(len2[i - 1] + 1, maxlen);
        len2.push_back(maxlen);
    }
    sort(len2.begin(), len2.end());
    return max(len[len.size() - 1], len2[len2.size() - 1]);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int x[9] = {9, 4, 2, 10, 7, 8, 8, 1, 9};
    vector<int> n(x, x + 9);
    cout << maxTurbulenceSize(n);
    return 0;
}
