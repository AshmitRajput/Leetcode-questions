class Solution {
public:
    void dfs(vector<vector<int>>&ls,vector<int>&vis,int i){
        vis[i]=1;
        for(int j=0;j<ls.size();j++){
            if(!vis[j]&&ls[i][j]==1) dfs(ls,vis,j);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(isConnected,vis,i);
            }
        }
        return count;

    }
};