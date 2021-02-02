#include <iostream>
#include <stdio.h>
#include "vector"
#include "string"

using namespace std;

int pivotIndex(vector<int>& nums) {
    int leftsum=nums[0],rightsum=nums[nums.size()-1];
    int i=1,j=nums.size()-2;
    if (nums.size()<2)
        return -1;
    while (true){
        if (i==j)
            return leftsum==rightsum?i:-1;
        if (leftsum<rightsum) {
            leftsum+=nums[i];
            i++;
        }
        else if (leftsum>rightsum) {
            rightsum+=nums[j];
            j--;
        }
        else
        if (i==j)
            return i;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int x[6] = {1,7,3,6,5,6};
    vector<int> n(x, x + 6);
    cout << pivotIndex(n);
    return 0;
}
