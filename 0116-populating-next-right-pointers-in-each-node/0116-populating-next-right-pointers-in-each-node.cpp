/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root->left) return root; // base case: leaf or null

        // Connect the two children of this node
        root->left->next = root->right;

        // Connect right child to the next subtree's left child (if it exists)
        if (root->next) {
            root->right->next = root->next->left;
        }

        // Recurse into both subtrees
        connect(root->left);
        connect(root->right);

        return root;
    }
};