# <font color=black></font>[leetcode 17](https://leetcode.cn/problems/letter-combinations-of-a-phone-number)
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

 

示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

示例 2：

输入：digits = ""
输出：[]

示例 3：

输入：digits = "2"
输出：["a","b","c"]



自己做的话很简单，就是不断添加尾字符，但是我用的暴力索引，且空间很大，看一看官方题解：
# <font color=plum>官方题解</font>
``` C++
class Solution {
public:
    string tmp;
    vector<string> res;
    vector<string> board={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};//就是用来存储的，有的还用了地图匹配，
    void DFS(int pos,string digits){
        if(pos==digits.size()){
            res.push_back(tmp);
            return;
        }
        int num=digits[pos]-'0';
        for(int i=0;i<board[num].size();i++){
            tmp.push_back(board[num][i]);//先给tmp尾加上一个，在DFS，就是，以23举例，tmp本来是空的，
            DFS(pos+1,digits);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return res;
        DFS(0,digits);
        return res;
    }
};
```
以234举例，其实就是，tmp的变化回溯过程：
- abc
- def
- ghi

a->ad-><font color=plum>adc</font></font><font color=yellowgreen>(到底了，就把abc push,然后就被弹出)</font>->ad-><font color=plum>adh</font>->ad-><font color=purple>adi</font>-><font color=seagreen>ae</font>->**(ad的DFS执行完毕，于是到pop了，pop后变为ae)**...
这样就可以回溯，但是时间肯定会稍长一点。