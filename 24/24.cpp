#include<iostream>
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode(){;}
};

ListNode* swapPairs(ListNode * head)
{
    if(head->next==nullptr)
    return head;
    ListNode* head1=head;

    ListNode* now=head;
    head = head ->next;
    while(now&&now->next){
        ListNode *tmp = now->next->next;
        head1->next = now->next;
        now->next->next = now;
        head1 = now ;
        now -> next = tmp;
        now = tmp;
        
    }
    // while(head){
    //     std::cout<<head->val<<std::endl;
    //     head = head ->next;
    // }
    return head;

}
int main(){
    ListNode *head;
    ListNode data[6];
    for(int i = 0;i < 4;i++)
    {
        data[i].val = i+1;
        data[i].next = &data[i+1];
    }
    head = &data[0];
    swapPairs(head);
}