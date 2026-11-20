class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        if (mini + k >= maxi - k)
            return 0;
        else
            return ((maxi - k) - (mini + k));
    }
};