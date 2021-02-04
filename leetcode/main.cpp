#include <iostream>
#include <stdio.h>
#include "vector"
#include "string"

using namespace std;

int search(vector<int>& nums, int target) {
    int index=-1;
    for (int i = 0; i < nums.size(); ++i) {
        cout<<nums[i];
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

int main() {
    std::cout << "Hello, World!" << std::endl;
    int x[7] = {4,5,6,7,0,1,2};
    vector<int> n(x, x + 7);
    cout << search(n,0);
    return 0;
}
