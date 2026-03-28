class Solution {
public:
    void f(vector<int>&arr,int ind, int n, vector<int>&ds,vector<vector<int>>&ans, int k){
        if(n==0&&k==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<arr.size();i++){
            if(arr[i]>n||k<=0) break;
            ds.push_back(arr[i]);
            f(arr,i+1,n-arr[i],ds,ans,k-1);
            ds.pop_back();
        }


    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr(9,0);
        for(int i=0;i<9;i++){
            arr[i]=i+1;
        }
        vector<int>ds;
        vector<vector<int>>ans;
        f(arr,0,n,ds,ans,k);
        return ans;
    }
};