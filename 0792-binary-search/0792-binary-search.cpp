class Solution {
public:

    int binarysearch(vector<int>& nums, int target,int start,int end){
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) return binarysearch(nums,target,start,mid-1);
            else if(nums[mid]<target) return binarysearch(nums,target,mid+1,end);
        }
        return -1;
        
    }

    int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        int ans = binarysearch(nums,target,start,end);
        return ans;
        
    }
};