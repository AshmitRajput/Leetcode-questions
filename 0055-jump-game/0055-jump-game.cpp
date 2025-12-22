class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump=nums[0];
        for(int i=0;i<nums.size();i++){
            jump=max(jump,nums[i]);
            if(jump==0&&i!=nums.size()-1) return false;
            jump--;
        }
        return true;
    }
};