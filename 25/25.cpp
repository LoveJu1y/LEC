#include<iostream>

class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){;}
    ListNode(int x):val(x),next(nullptr){;}
    ListNode(int x,ListNode* n):val(x),next(n){;}
    ~ListNode(){;}
};

ListNode** enough_k(ListNode * head,int k)
{
    ListNode** ret;
    ret = new(ListNode*[k]);
    for(int i =0;i<k;i++)
    {
        if(head)
        {
            ret[i] = head;
            head = head->next;
        }
        else return nullptr;
    }
    return ret;
}
ListNode* reverseKGroup(ListNode* head, int k)
{
    ListNode **arr= enough_k(head,k);
    if (!arr) return head;
    ListNode* head_arr = head;
    ListNode* end_Arr = arr[k-1];
    head = end_Arr;
    while(1)
    {   ListNode *tmp = end_Arr->next;
        for(int i =k-1;i>0;i--)
        {
            arr[i]->next = arr[i-1];
        }
        head_arr->next = tmp;
        if(!tmp) return head;
        
        delete arr;
        arr = enough_k(head_arr->next,k);
        if (!arr) 
        {
            return head;
        }
        head_arr ->next= arr[k-1];
        head_arr  = arr[0];
        end_Arr = arr[k-1];
    }

    return nullptr;
}
int main(void)
{
    ListNode data[5];
    for(int i = 0;i < 4;i++)
    {
        data[i].val = i+1;
        data[i].next = &data[i+1];
    }
    ListNode* head = &data[0];
    ListNode* a = reverseKGroup(head,2);
     while(a){
        std::cout<<a->val<<std::endl;
        a = a ->next;
    }
}