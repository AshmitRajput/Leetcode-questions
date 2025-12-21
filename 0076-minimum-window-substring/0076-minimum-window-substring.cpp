class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0;
        int n=s.size(),m=t.size(),minlen=1e9,count=0,sindex=-1;
        unordered_map<char,int>mpp;
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        while(r<n){
            if(mpp[s[r]]>0)count+=1;
            mpp[s[r]]--;
            while(count==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sindex=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0)count--;
                l++;

            }
            r++;
        }
        return sindex==-1?"":s.substr(sindex,minlen);

    }
};