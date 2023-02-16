/*
给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。

 

示例 1：

输入：s = "aacecaaa"
输出："aaacecaaa"

示例 2：

输入：s = "abcd"
输出："dcbabcd"
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string kmp(string s)
{
    int n=s.size();
    if(!n) return s;
    int next[n];
    next[0]=0;
    int j=0,i=1;
    while(i<n)
    {
        if(s[i]==s[j])
        {
            next[i]=j+1;;//用j+1就是长度的意思，因为j是从零开始的。
            i++;
            j++;
        }
        else if(j>0)
        {
            j=next[j-1];
        }
        else{
            next[i++]=0;
        }
    }
    int p=0;
    for(int i=n-1;i>=0;i--)
    {
        if(p==0||s[p]==s[i])
        {
            p++;
        }
        else{
            p=next[p-1];
            i++;
        }
    }
    string add = (p == n) ? "" : s.substr(p);
    reverse(add.begin(),add.end());
    return add+s;
}
int main(void)
{
    string a="aacecaaa";
    string b=kmp(a);
    cout<<b;
}