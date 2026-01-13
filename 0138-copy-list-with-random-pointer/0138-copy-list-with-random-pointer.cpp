/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* curr = head;

        while(curr != nullptr){
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = curr->next->next;
        }
        curr = head;
        while(curr != nullptr){
            if(curr->random != nullptr){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        curr = head;
        Node* newHead = head->next;
        Node* newCurr = newHead;
        while(curr != nullptr){
            curr->next = curr->next->next;
            curr = curr->next;
            if(newCurr->next){
                newCurr->next = newCurr->next->next;
                newCurr = newCurr->next;
            }
        }
        return newHead;
    }
};