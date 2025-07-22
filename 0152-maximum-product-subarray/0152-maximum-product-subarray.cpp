class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int prod=nums[i];
            if(prod>maxi) maxi=prod;
            for(int j=i+1;j<nums.size();j++){
                prod *= nums[j];
                if(prod>maxi) maxi=prod;
            }
        }
        return maxi;
    }
};