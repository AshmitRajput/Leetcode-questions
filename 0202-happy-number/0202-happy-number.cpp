class Solution {
public:
    bool isHappy(int n) {
        set<int>s;
        if(n==1) return true;
        while(n!=1){
            int ans=0;
            while(n!=0){
                int digit=n%10;
                n=n/10;
                ans+=digit*digit;
            }
            n=ans;
            if(s.find(ans)!=s.end()) return false;
            s.insert(ans);
        }
        return true;
    }
};