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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL||head->next==NULL) return NULL;
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count==n){
            ListNode* newhead=head->next;
            return newhead;
        }
        temp=head;
        count=count-n;
        ListNode* prev=head;
        while(temp!=NULL){
            count--;
            if(count==0)break;
            temp=temp->next;
        }
        ListNode* del=temp->next;
        
        temp->next=temp->next->next;
        delete del;
        return head;

    }
};