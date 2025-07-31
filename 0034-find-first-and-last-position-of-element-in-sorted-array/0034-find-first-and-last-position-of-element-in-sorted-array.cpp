class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>arr = {-1,-1};
        int flag=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                if(flag==0){
                    arr[0]=i;
                    arr[1]=i;
                    flag=1;
                }
                else{
                    arr[1]=i;
                }
            }
            if(nums[i]>target) break;
        }
        return arr;
    }
};