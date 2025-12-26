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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        int level=0;
        queue<pair<TreeNode*,int>>q;
        map<int,int>mpp;
        q.push({root,level});
        while(!q.empty()){
            auto p=q.front();
            TreeNode* node=p.first;
            int level=p.second;
            q.pop();
            if(node->left!=NULL){
                q.push({node->left,level+1});
            }
            if(node->right!=NULL){
                q.push({node->right,level+1});
            }
            
            mpp[level]=node->val;

        }
        for(auto &it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};