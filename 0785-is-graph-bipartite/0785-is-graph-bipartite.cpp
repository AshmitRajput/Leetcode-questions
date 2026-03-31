class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int>q;
        int n=graph.size();
        int color[n];
        for(int i=0;i<n;i++) color[i]=-1;
        color[0]=0;
        for(int i=0;i<n;i++){
            if(i==0 || color[i]==-1){
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto it:graph[node]){
                        if(color[it]==-1){
                            color[it]=!color[node];
                            q.push(it);
                        }
                        else if(color[it]==color[node]) return false;
                    }
                }
            }
            
        }
        return true;
    }
};