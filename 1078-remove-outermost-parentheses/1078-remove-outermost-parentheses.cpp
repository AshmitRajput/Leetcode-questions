//Final optimized solution after looking at different approaches.
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

//2nd Attempt - optimized solution
class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans;
        for(int i=0;i<s.length();i++){
           if(s[i]=='('){
            if(count>0) ans += s[i];
            count++;
           }
           else{
            count--;
            if(count>0) ans += s[i];
           }
        }
        return ans;
    }
};


//1st Attempt.
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

