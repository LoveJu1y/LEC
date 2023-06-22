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
        //  if(num==0)
        //  return nullptr;
        //  if(num==1)
        //  return lists[0];
    ListNode *ide;ListNode*ret;
    ide=new ListNode(0);
    ret=ide;
    int flag=0;
    while(flag<num)
    {
       int k=0;
        for(int i=0;i<num;i++)
        {
            if(lists[i]!=nullptr) 
           { k=i;break;}
        }
        for(int i=k;i<num;i++)
        {
           
            if(lists[i]==nullptr) continue;  
            if(lists[i]->val<lists[k]->val)
            k=i;
        }
                //cout<<lists[k]->val;
                if(lists[k]){
                ide->next=lists[k];
                ide=ide->next;
                lists[k]=lists[k]->next;
                } if(lists[k]==nullptr)flag++;

    }
    return ret->next;
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
    a=c;
   // mergeKLists(lists);
    print(a);
}