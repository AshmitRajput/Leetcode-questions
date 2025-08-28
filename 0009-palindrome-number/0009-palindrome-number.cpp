class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10 == 0 && x != 0)){
            return false;
        }
        int rev = 0;
        int temp = x;
        while(temp>0){
            int digit = temp%10;
            if((rev>INT_MAX/10) || (rev<INT_MIN/10)){
                return false;
            }
            rev = rev*10 + digit;
            temp = temp/10;
        }
        if(rev == x){
            return true;
        }
        else{
            return false;
        }
    }
};