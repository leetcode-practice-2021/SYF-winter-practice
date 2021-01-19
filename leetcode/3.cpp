//
// 3 无重复字符的最长字串
// Created by 师域飞 on 2021/1/19.
//
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;
void  run3();

class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        char *p=&s[1];
        int len=s.size();
        char temp[len];
        temp[0]=s[0];

        int max=1;
        int  index=1;
        for (int i = 0; i < len; ++i,p++) {

            for (int j = i; j < len; ++j) {
                if (*p=='\0')
                    break;
                for (char* ch = &s[0]; ch < p; ++ch) {
                    if(p[0]==ch[0])
                        break;
                    else{
                        temp[index++]=ch[0];
                    }
                }
                if (max<index)
                    max=index;
                index=1;
            }
        }
        return max;
    }
};

void  run3(){
    Solution3 solution;
    int x=solution.lengthOfLongestSubstring("obj,2");
    cout<<x;
}