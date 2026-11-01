class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool>mpp;
        for(auto it:nums1){
            mpp[it]=true;
        }
        vector<int>ans;
        for(auto it:nums2){
            if(mpp[it]){
                ans.push_back(it);
                mpp[it]=false;
            }
        }
        return ans;
    }
};