class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mpp;
        for(auto c:s){
            mpp[c]++;
        }
        int ans=-1;
        for(int i=0;i<s.size();i++){
            if(mpp[s[i]]==1){
                ans=i;
                return ans;
            }
        }
        return ans;
    }
};