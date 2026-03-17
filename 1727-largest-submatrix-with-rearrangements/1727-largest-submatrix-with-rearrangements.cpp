class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxarea=0;
        vector<vector<int>>presum(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=matrix[i][j];
                if(matrix[i][j]==0) sum=0;
                presum[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++){
            sort(presum[i].begin(),presum[i].end());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int height=presum[i][j];
                int area=height*(m-j);
                maxarea=max(maxarea,area);
            }
        }
        return maxarea;

    }
};