class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,maxlen=0,zero=0;

        for (int right=0;right<nums.size();++right) {
            if (nums[right]==0) {
                zero++;
            }
            while (zero>k) {
                if (nums[l]==0) {
                    zero--;
                }
                l++;
            }
            maxlen=max(maxlen,right-l+1);
        }
        return maxlen;
    }
};