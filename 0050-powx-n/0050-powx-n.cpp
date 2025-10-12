class Solution {
public:
    double myPow(double x, int n) {
        long long nn=n;
        if(nn==0) return 1;
        if(nn<0) {
            nn = abs(nn);
            x = 1/x;
        }
        if(nn%2==0){
            return myPow(x*x, nn/2);
        }
        else{
            return x*myPow(x, nn-1);
        }
    }
};