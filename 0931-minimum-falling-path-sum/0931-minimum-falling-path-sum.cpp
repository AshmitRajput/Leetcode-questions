class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>prev(m,0);
        for(int i=0;i<m;i++) prev[i]=matrix[0][i];

        for(int i=1;i<n;i++){
            vector<int>curr(m,0);
            for(int j=0;j<m;j++){
                int u=matrix[i][j]+prev[j];
                int ld=matrix[i][j];
                if(j>0) ld+=prev[j-1];
                else ld+=1e8;
                int rd=matrix[i][j];
                if(j+1<m) rd+=prev[j+1];
                else rd+=1e8;

                curr[j]=min(u,min(rd,ld));
            }
            prev=curr;
        }
        
        int mini=1e8;
        for(int i=0;i<m;i++){
            mini=min(mini,prev[i]);
        }
        return mini;
    }
};