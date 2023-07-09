//字符串匹配算法！
#include<iostream>
#include<string>
#include <vector>
using namespace std;
int strStr(string haystack,string needle){
    if(haystack.length()<needle.length())
    return -1;
    int* next;
    next = new int [needle.length()]{-1};

	for (int i = 0, j = 0; i < haystack.length(); i++)
	{
		while (j > 0 && haystack[i] != needle[j])
		{
			j = next[j - 1];
		}
		if (haystack[i] == needle[j])
		{
			j++;
		}
		if (j == needle.length())
		{
			return i - needle.length();
			
		}
        if(i==haystack.length()-1)
        {return -1;}
	}
    delete[] next;
	return 0;
}



vector<int> Next(string pattern)
{
	vector<int> next;
	next.push_back(0);	//next容器的首位必定为0
	for (int i = 1, j = 0; i < pattern.length(); i++)
	{
		while (j > 0 && pattern[j] != pattern[i])//此时出现了不配对，也就意味着，第i位不能很好的匹配了，比如aac aae
		{ 
			j = next[j - 1];
		}
		if (pattern[i] == pattern[j])
		{
			j++; 
		}
		next.push_back(j);
        cout<<j<<' ';
	}
	return next;
}

int main()
{
    


	string pattern = "ababc", target = "mississippi";
	vector<int>next = Next(pattern);

	// for (int i = 0, j = 0; i < target.length(); i++)
	// {
	// 	while (j > 0 && target[i] != pattern[j])
	// 	{
	// 		j = next[j - 1];
	// 	}
	// 	if (target[i] == pattern[j])
	// 	{
	// 		j++;
	// 	}
	// 	if (j == pattern.length())
	// 	{
	// 		cout << "Found pattern at " << i - j << " position" << endl;
	// 		j = next[j - 1];
	// 	}
	// }
    // cout<<strStr(target,pattern)<<endl;;
	// return 0;
}
