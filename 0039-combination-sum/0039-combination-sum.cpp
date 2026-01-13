class Solution {
public:
    void find(int index,vector<int>& candidates,int target,vector<vector<int>>& ans,vector<int>ds){
        if(candidates.size()==index){
            if(target==0) ans.push_back(ds);
            return;
        }
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            find(index,candidates,target-candidates[index],ans,ds);
            ds.pop_back();
        }
        find(index+1,candidates,target,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        find(0,candidates,target,ans,ds);
        return ans;
    }
};