class Solution {
public:
    bool check(int n){
        int count=0;
        int size=0;
        while(n>0){
            size++;
            int d=n%10;
            n=n/10;
            if(d==0||d==1||d==8) count++;
            if(d==3||d==4||d==7) return false;
        }
        if(count==size) return false;
        else return true;

    }
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            if(check(i)) ans++;
        }
        return ans;
        
    }
};