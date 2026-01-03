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
    void parentmap(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& mpp){
        if(!root)return;
        if(root->left){
            mpp[root->left]=root;
            parentmap(root->left,mpp);
        }
        if(root->right){
            mpp[root->right]=root;
            parentmap(root->right,mpp);
        }
        
    }
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode*,TreeNode*>mpp;
        unordered_map<TreeNode*,int>vis;
        mpp[root]=NULL;
        parentmap(root,mpp);
        int a=0;
        while(root->left!=NULL){
            root=root->left;
        }
        while(true){
            vis[root]=1;
            a++;
            if(k==a) return root->val;
            if (root->right && !vis[root->right]) {
                root = root->right;
                while (root->left) root = root->left;
            }
            else {
                TreeNode* p = mpp[root];
                while (p && vis[p]) {
                    root = p;
                    p = mpp[root];
                }
                root = p;
            }

        }
        return -1;


    }
};