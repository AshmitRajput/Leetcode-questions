class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1==0&&need2==0) return 0;
        long long total=0;
        if(costBoth>=cost1+cost2){
            total+=1LL*cost1*need1;
            total+=1LL*cost2*need2;
        }
        else{
            int mini= min(need1,need2);
            total+=1LL*mini*costBoth;
            need1-=mini;
            need2-=mini;
            total+=min(1LL*need1*cost1,1LL*costBoth*need1);
            total+=min(1LL*need2*cost2,1ll*costBoth*need2);
        }
        return total;
        
    }
};