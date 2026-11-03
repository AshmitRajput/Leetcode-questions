class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi)maxi=nums[i];
        }
        int ans=0;
        for(auto it:nums){
            ans+=abs(maxi-it);
        }
        return ans;
    }
};