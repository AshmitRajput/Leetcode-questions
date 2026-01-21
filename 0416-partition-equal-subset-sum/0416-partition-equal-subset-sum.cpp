class Solution {
public:
    bool subsetsum(vector<int>& nums,int k,int n){
        vector<bool>prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0]=true;
        if(nums[0]<=k) prev[nums[0]]=true;
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=k;target++){
                bool nottake=prev[target];
                bool take=false;
                if(nums[ind]<=target) take=prev[target-nums[ind]];
                curr[target]=take|nottake;

            }
            prev=curr;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total%2==1) return false;
        int target=total/2;
        return subsetsum(nums,target,n);

    }
};