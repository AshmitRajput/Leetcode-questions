/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int>mpp;
        bool ans=true;
        while(head!=NULL){
            if(mpp[head]){
                ans=false;
                break;
            }
            mpp[head]++;
            head=head->next;
        }
        return !ans;
    }
};