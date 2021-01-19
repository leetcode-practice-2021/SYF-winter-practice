#include <iostream>
#include <stdio.h>
#include "vector"
#include "string"
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    int x[6]={-1,0,1,2,-1,-4};
    vector<int>obj(x,x+6);
    threeSum(obj);
    return 0;
}
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<int> temp;
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    for (int i = 0; i < nums.size()-2; ++i) {
        for (int j = i+1; j < nums.size()-1; ++j) {
            for (int k = j+1; k < nums.size(); ++k) {
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
