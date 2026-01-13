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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode* temp=head;
        int count=1;
        while(temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        if(k%count==0) return head;
        ListNode* temp2=head;
        for(int i=0;i<count-(k%count)-1;i++){
            temp2=temp2->next;
        }
        temp->next=head;
        head=temp2->next;
        temp2->next=NULL;
        return head;
    }
};