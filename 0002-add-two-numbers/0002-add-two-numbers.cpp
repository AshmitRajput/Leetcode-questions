/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,sum=l1->val+l2->val;
        int num=sum;
        if(sum>=10){
            carry=1;
            num=sum%10;
        }
        ListNode* newhead = new ListNode(num);
        l1=l1->next;l2=l2->next;
        ListNode* temp=newhead;
        while(l1!=NULL||l2!=NULL){
            if(l1&&l2) sum=l1->val+l2->val+carry;
            else if(l1) sum=l1->val+carry;
            else if(l2) sum=l2->val+carry;
            if(sum>9){
                carry=1;
                num=sum%10;
            }
            else{
                carry=0;num=sum;
            }
            ListNode* temp1=new ListNode(num);
            temp->next=temp1;
            temp=temp1;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(carry){
            ListNode* temp1=new ListNode(1);
            temp->next=temp1;
        }
        return newhead;
    }
};