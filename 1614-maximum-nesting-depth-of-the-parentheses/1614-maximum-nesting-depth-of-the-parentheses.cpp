class Solution {
public:
    int maxDepth(string s) {
        int l = s.length();
        int count=0,maxi=0;
        for(int i=0;i<l;i++){
            if(s[i]=='(') count++;
            else if(s[i]==')') count--;
            if(count>maxi) maxi=count;
        }
        return maxi; 
    }
};