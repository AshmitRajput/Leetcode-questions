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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        stack<TreeNode*>st;
        stack<TreeNode*>st2;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            st2.push(root);
            if(root->left!=NULL) st.push(root->left);
            if(root->right!=NULL) st.push(root->right);
        }
        while(!st2.empty()){
            TreeNode* node2=st2.top();
            ans.push_back(node2->val);
            st2.pop();
        }
        return ans;
    }
};