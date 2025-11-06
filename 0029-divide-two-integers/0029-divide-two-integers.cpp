class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign=true;
        if(dividend<0 && divisor>0) sign=false;
        else if(dividend>0 && divisor<0) sign=false;

        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long n = labs(dividend);
        long d = labs(divisor);
        long ans=0;
        while(n>=d){
            int count=0;
            while(n>=(d<<(count+1))) count++;
            ans+=(1L<<count);
            n = n-(d*(1L<<count));
        }
        if(ans>INT_MAX && sign==true) return INT_MAX;
        if(ans>INT_MAX && sign==false) return INT_MIN;
        else{
            return sign?ans:(-1*ans);
        }
    }
};