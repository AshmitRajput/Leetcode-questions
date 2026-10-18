class Solution {
    int ans=1e9;
public:
    void solve(vector<int>&price, vector<vector<int>>&special, vector<int>&needs, int inx, int n, int cost){
        if(cost>ans) return;
        if(inx==special.size()){
            for(int i=0;i<n;i++){
                cost+=needs[i]*price[i];
            }
            ans=min(ans,cost);
            return ;
        }
        bool f1=true;
        for(int i=0;i<n;i++){
            if(needs[i]<special[inx][i]){
                f1=false;
                break;
            }
        }
        if(f1){
            for(int i=0;i<n;i++){
                needs[i]-=special[inx][i]; 
            }
            solve(price,special,needs,inx,n,cost+special[inx][n]);
            for(int i=0;i<n;i++){
                needs[i]+=special[inx][i]; 
            }
        }
        solve(price,special,needs,inx+1,n,cost);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n=price.size();
        solve(price,special,needs,0,n,0);
        return ans;
    }
};