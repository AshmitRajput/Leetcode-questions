class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0,start=0;
        string ans;
        for(int i=0;i<s.length();i++){
           if (s[i] == '(') count++;
            else count--;
            if ( count == 0) {
                ans += s.substr(start + 1, i - start - 1);
                start = i + 1;
            }

        }
        return ans;
    }
};