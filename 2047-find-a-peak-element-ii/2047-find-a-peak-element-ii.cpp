//First approach-greedy hill climbing but in an efficient manner, similar to binary search.
//it finds larger neighbour and jumps, and when count for all 4 neighbours to be smaller
// is satisfied, ans is returned
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int ind1=0,ind2=0,row=mat.size(),col=mat[0].size();
        int count=0;
        while(count<4){
            int ele=mat[ind1][ind2];
            if(ind2+1<col){
                if(mat[ind1][ind2+1]<ele){
                    count++;
                    if(count>=4) break;
                }
                else{
                    ind2=ind2+1;
                    count=0;
                    ele=mat[ind1][ind2];
                }
            }
            else count++;
            if(ind2-1>=0){
                if(mat[ind1][ind2-1]<ele){
                    count++;
                    if(count>=4) break;
                }
                else{
                    ind2=ind2-1;
                    count=0;
                    ele=mat[ind1][ind2];
                }
            }
            else count++;
            if(ind1+1<row){
                if(mat[ind1+1][ind2]<ele){
                    count++;
                    if(count>=4) break;
                }
                else{
                    ind1=ind1+1;
                    count=0;
                    ele=mat[ind1][ind2];
                }
            }
            else count++;
            if(ind1-1>=0){
                if(mat[ind1-1][ind2]<ele){
                    count++;
                    if(count>=4) break;
                }
                else{
                    ind1=ind1-1;
                    count=0;
                    ele=mat[ind1][ind2];
                }
            }
            else count++;
        }
        return {ind1,ind2};
    }
};


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
