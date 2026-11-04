class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1) return true;
        if(n%10!=4 && n%10!=6 ) return false;
        while(n!=1){
            if(n%4==0) n=n/4;
            else{
                return false;
            }
        }
        return true;
    }
};