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
        vector<int>ans{ind1,ind2};
        return ans;
    }
};