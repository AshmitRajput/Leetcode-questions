class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_r = 0;

        for (int i=0;i<(int)nums.size();i++) {
            if (max_r < i) return false;
            max_r = max(max_r, i + nums[i]);
        }
        return true;
    }
};