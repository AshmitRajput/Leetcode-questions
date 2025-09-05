class Solution {
public:
    int MaxIndex(vector<vector<int>>& mat, int n,int m, int col){
        int index = -1;
        int maxvalue = -1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxvalue){
                maxvalue=mat[i][col];
                index=i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int rowmax=MaxIndex(mat,n,m,mid);
            int left=mid-1>=0 ? mat[rowmax][mid-1]:-1;
            int right=mid+1<m ? mat[rowmax][mid+1]:-1;
            if(mat[rowmax][mid]>left&&mat[rowmax][mid]>right) return {rowmax,mid};
            else if(mat[rowmax][mid]<left) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};