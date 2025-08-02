class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i=i+2){
            if(nums.size()==1) return nums[0];
            else if(nums[i]!=nums[i+1] || i==nums.size()-1) return nums[i];
        }
        return -1;

    }
};