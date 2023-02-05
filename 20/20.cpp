#include<iostream>
using namespace std;
class ListNode
{
    public:
    int val;
    ListNode *next;
    ListNode(int valuee=0,ListNode *ne=NULL):val(valuee),next (ne){;}
    ~ListNode(){;}
};
// ListNode* removeNthFromEnd(ListNode* head, int n)
// {
// ;
// }
int num=0; 
void op(int now,ListNode *head,int n)
{
    if(head)
    {
        num++;
        op(now+1,head->next,n);
    }
    if(now==num-n-1)
       { 
        head->next=head->next->next;
        }
}
int main(void)
{
    int n=2;
    ListNode *headd;
    headd=new ListNode(1);
    ListNode * head=headd;
    // for(int i=0;i<7;i++)
    // {
    //    headd->next=new ListNode(i+2);
    //    headd=headd->next;
    // }
    ListNode *bef=new ListNode(999,head);
    op(0,bef,n);
    while(head)
    {
        cout<<head->val;
        head=head->next;
    }
}