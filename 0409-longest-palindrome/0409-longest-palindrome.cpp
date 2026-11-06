class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mpp;
        int cnt=0;
        for(auto ch:s){
            mpp[ch]++;
            if(mpp[ch]==2){
                cnt+=2;
                mpp[ch]=0;
            }

        }
        for(auto ch:s){
            if(mpp[ch]){
                cnt++;
                break;
            }
        }
        return cnt;

    }
};