class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size(),pos=0,neg=1;
        vector<int>ans(n,0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans[pos]=nums[i];
                pos = pos+2;
            }
            if(nums[i]<0){
                ans[neg]=nums[i];
                neg=neg+2;
            }
        }
        return ans;
        
    }
};