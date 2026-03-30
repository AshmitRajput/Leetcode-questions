class Solution {
public:
    void dfs(vector<vector<int>>&ls,vector<int>&vis,int start){
        int node=start;
        vis[node]=1;
        for(auto it:ls[node]){
            if(!vis[it]) dfs(ls,vis,it);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int start=0;
        vector<vector<int>>ls(n);
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&isConnected[i][j]==1){
                    ls[i].push_back(j);
                    ls[j].push_back(i);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(ls,vis,i);
            }
        }
        return count;

    }
};