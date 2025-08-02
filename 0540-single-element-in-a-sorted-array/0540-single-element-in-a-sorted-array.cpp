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


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left<right) {
            int mid=(left+right)/2;
            if (mid%2==1) mid--;
            if (nums[mid]!=nums[mid+1]) right = mid; 
            else {
                left = mid + 2;
            }
        }
        return nums[left];

    }
};
