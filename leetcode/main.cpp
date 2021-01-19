#include <iostream>
#include <stdio.h>
#include "string"
using namespace std;

int lengthOfLongestSubstring(string s);
int main() {
    std::cout << "Hello, World!" << std::endl;
    int x=lengthOfLongestSubstring("pwwkew");
    cout<<x;
    return 0;
}

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