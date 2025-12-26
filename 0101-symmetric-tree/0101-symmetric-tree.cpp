/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root==NULL||sym(root->left,root->right);
    }
    bool sym(TreeNode* node, TreeNode* node2){
        if(node==NULL||node2==NULL){
            return node==node2;
        }
        if(node->val!=node2->val) return false;
        return sym(node->right,node2->left)&&sym(node->left,node2->right);
    }
};