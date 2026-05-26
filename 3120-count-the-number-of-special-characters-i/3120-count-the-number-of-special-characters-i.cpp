class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans=0;
        unordered_map<int,int>mpp;
        for(auto it:word){
            int ch=it;
            mpp[ch]++;
        }
        for(int i=0;i<26;i++){
            if(mpp[i+65]&&mpp[i+97]) ans++;
        }
        return ans;
    }
};