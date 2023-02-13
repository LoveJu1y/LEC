#include<iostream>
#include<vector>
using namespace std;
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode(){;}
};
void  print(ListNode*list)
{
    ListNode*a=list;
    while(a!=NULL)
    {
        cout<<a->val<<' ';
        a=a->next;
    }
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    
        int num=lists.size();
    ListNode *ide;
    bool flag=1;
    while(flag)
    {
        flag=0;
        for(int i=0;i<num;i++)
        {
            if(lists[i]==NULL) continue;
            int k=i;
            for(int j=i+1;j<num;j++)
            {
                if(lists[j]==NULL) continue;
                if(lists[k]->val<lists[j]->val)
                k=j;
            }
            if(i!=k)
            {
                ide=lists[k];
                ide=ide->next;
                lists[k]=lists[k]->next;
                flag=1;
            }
        }
        
    }
    print(ide);
    return ide;
}
int main(void)
{
    vector<ListNode*>lists;
    ListNode *a,*b,*c;
    ListNode*aaa=a;
    ListNode*bbb=b;
    ListNode*ccc=c;
    for(int i=0;i<3;i++)
    {
        ListNode aa(i);
        a=&aa;
        a=a->next;
         ListNode bb(i+3);
        b=&bb;
        b=b->next;
         ListNode cc(i+6);
        c=&cc;
        c=c->next;
    }
    // for(int i=0;i<2;i++)
    // {
    //     a[i]->next=a[i+1];
    //     b[i]->next=b[i+1];
    //     c[i]->next=c[i+1];
    // }
    lists.push_back(aaa);
    lists.push_back(bbb);
    lists.push_back(ccc);
   // mergeKLists(lists);
    print(a);
}