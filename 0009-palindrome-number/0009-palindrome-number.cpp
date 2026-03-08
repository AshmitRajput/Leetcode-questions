class Solution {
public:
    bool isPalindrome(int x) {
        int ans  = 0;
        int temp = x;
       
        if(x<0){
            return false;
        }
        while( temp != 0) {
            
            int digit = temp % 10;
            
            if( (ans > INT_MAX/10) || (ans < INT_MIN/10)) {
                return 0;
            }
            
            ans = (ans * 10) + digit;
            temp = temp / 10;
            
        }
        
        if(ans==x){
            return true;
        }
        else
        return false;
    }
};