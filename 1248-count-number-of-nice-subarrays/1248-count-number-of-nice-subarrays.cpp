class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l=0,r=0;
        int odd=0,count=0,total=0;
        while(r<nums.size()){
            if (nums[r]&1){
                odd++;
                if (odd>=k) {
                    count=1;
                    while(!(nums[l++]&1))count++;
                    total+=count;
                }
            } else if (odd>=k) total+=count;
            r++;
        }
        return total;
    }
};