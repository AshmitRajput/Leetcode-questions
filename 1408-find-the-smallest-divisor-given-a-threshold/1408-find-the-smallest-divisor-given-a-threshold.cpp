class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(), nums.end()),n=nums.size();
        while (low<high) {
            int mid=(low+high)/2;
            int sum=0;
            for (int i=0;i<n;i++) {
                sum += (nums[i]+mid-1)/mid;
            }
            if(sum<=threshold) high=mid; 
            else {
                low=mid+1;
            }
        }
        return low;
    }
};