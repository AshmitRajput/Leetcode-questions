class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return -1;
        int ans=INT_MAX;
        int dist=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]==nums[j]&&nums[j]==nums[k]){
                        dist=abs(i-j)+abs(j-k)+abs(i-k);
                        ans=min(ans,dist);
                    }
                }
            }
        }
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};