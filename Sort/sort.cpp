#include<iostream>
using namespace std;

//这一部分主要用于稍微熟练以下常见的集中排序

///冒泡排序
//15,23,4,56,44,55,7,122,35,69};
void insert(int*a,int N)
{ 
    for(int i=1;i<N;i++)
    {
        int k=a[i];
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]>k) 
            {a[j+1]=a[j];a[j]=k;}
            else break;
            
        }
    }
}
void um(int *a,int N)
{
    int i=1;
    while(i<N)
    for(int j=0;j<N;j+=i)
    {
        
    }
}
int* choose(int *a,int N)
{
    for(int i=0;i<N;i++)
    {
        int now=i;
        for(int j=i+1;j<N;j++)
        {
            if(a[j]<a[now]) now=j;
        }
        if(now!=i)
        {
            int ch=a[i];
            a[i]=a[now];
            a[now]=ch;
        }
    }
    return a;
}
void exchange(int *a,int i,int j)
{
    int tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
}
//int b[5]={3,5,1,2,6};
void print(int *a,int N)
{
    for(int i=0;i<N;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
void quicksort(int *a,int begin,int end)
{
    if(begin>=end)return;
    int randidx = begin+rand() % (end - begin +1);
    exchange(a,begin, randidx);
    int left=begin,right=end+1;
    while(1)
    {
        while(a[--right]>a[begin]);
        while(a[++left]<a[begin]) if(left>right) {break;}
       if(left>=right) break;
        exchange(a,left,right);
    }
    exchange(a,begin,right);print(a,4);
    quicksort(a,begin,right-1);
    quicksort(a,right+1,end);
}
/*
需要注意，这里面其实思路就是简单的，但是实现时，一定要和注意，越界判断和停止判断，一般来说，如果以begin为判断依据，那么右侧指针先行，极端情况是，
已经排好序，右侧指针直接到begin了，（还不能再right移动中庸right==left判断，因为他们会在left处相遇，此时在执行后续操作，begin和第一位就交换了。）所以
right就停在begin，left大于right，直接退出，吧begin和right交换就行。正常情况下，右侧指针移动，左侧移动，交换，最终右侧指针会移动在小于等于a[begin]上，这一点不需要怀疑
因为要么在begin，要么在之前最有一次交换的left处，这就是最终分割的位置，

*/
//当然还可以加入随机数种子，随机效果更好一点。
int main(void)
{
    int *a;
    a=new int[10]{15,23,4,56,44,55,7,122,35,69};
    int b[4]={5,2,3,1};
    quicksort(b,0,3);
    print(b,4);
}