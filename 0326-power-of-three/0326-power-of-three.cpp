class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        if(n%10!=1&&n%10!=9&&n%10!=3&&n%10!=7) return false;
        else{
            while (n % 3 == 0) {
            n /= 3;
            }
        }
        return n==1;

    }
};