#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    vector<string>now{""};
    vector<string> ret;
    ret=now;
    string digits="";
    int len=digits.size();
    for(int i=0;i<len;i++)
    {
        int j=now.size()-1;
        switch (digits[i])
        {
            case '2':
            {
                ret.clear();
                while(j>=0){
                    ret.push_back(now[j]+'a');ret.push_back(now[j]+'b');ret.push_back(now[j--]+'c');
                }
                now=ret;break;
            }
            case '3':
            {
                ret.clear();
                while(j>=0){
                    ret.push_back(now[j]+'d');ret.push_back(now[j]+'e');ret.push_back(now[j--]+'f');
                }
                now=ret;break;
            }
            case '4':
            {
                ret.clear();
                while(j>=0){
                    ret.push_back(now[j]+'g');ret.push_back(now[j]+'h');ret.push_back(now[j--]+'i');
                }
                now=ret;break;
            }
            case '5':
            {
                ret.clear();
               while(j>=0){
                    ret.push_back(now[j]+'j');ret.push_back(now[j]+'k');ret.push_back(now[j--]+'l');
               }
                now=ret;break;
            }
            case '6':
            {
                ret.clear();
                while(j>=0){
                    ret.push_back(now[j]+'m');ret.push_back(now[j]+'n');ret.push_back(now[j--]+'o');
                }
                now=ret;break;
            }
            case '7':
            {
                ret.clear();
                while(j>=0){
                    ret.push_back(now[j]+'p');ret.push_back(now[j]+'q');ret.push_back(now[j]+'r');ret.push_back(now[j--]+'s');
                }
                now=ret;break;
            }
            case '8':
            {
                ret.clear();
                while(j>=0){
                    ret.push_back(now[j++]+'t');ret.push_back(now[j++]+'u');ret.push_back(now[j--]+'v');
                }
                now=ret;break;
            }
            case '9':
            {
                ret.clear();
                while(j>=0)
                {
                    ret.push_back(now[j++]+'w');ret.push_back(now[j++]+'x');ret.push_back(now[j++]+'y');ret.push_back(now[j--]+'z');
                }
                    now=ret;break;
            }
        }
    }
    for(int i=0;i<ret.size();i++)
    {
        cout<<ret[i]<<"  ";
    }

}