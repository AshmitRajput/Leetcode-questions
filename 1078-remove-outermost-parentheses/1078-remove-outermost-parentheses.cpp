class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans;
        for(int i=0;i<s.length();i++){
            if(count==0&&s[i]=='(') count++;
            else if(s[i]=='('&&count>0){
                count++;
                ans += '(';
            }
            else if(s[i]==')'&&count>1){
                count--;
                ans += ')';
            }
            else if(s[i]==')'&& count==1) count--;
        }
        return ans;
    }
};