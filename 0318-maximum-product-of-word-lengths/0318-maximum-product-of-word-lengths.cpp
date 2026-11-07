class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size()-1;i++){
            unordered_map<char,int>mpp;
            int cnt=0;
            for(auto it:words[i]){
                mpp[it]++;
            }
            for(int j=i+1;j<words.size();j++){
                int cnt1=0;
                for(auto it:words[j]){
                    if(mpp[it]) break;
                    cnt1++;
                }
                int temp=words[i].length()*words[j].length();
                if(cnt1==words[j].length()) ans=max(ans,temp);
            }
        }
        return ans;
    }
};