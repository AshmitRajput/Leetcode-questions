class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1,prod2=1,cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt++;
            }
            if(nums[i]!=0) prod*=nums[i];
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(cnt>1) ans.push_back(0);
            else if(cnt==1){
                if(nums[i]!=0) ans.push_back(0);
                else ans.push_back(prod);
            }
            else{
                ans.push_back(prod/nums[i]);
            }
        }
        return ans;
    }
};