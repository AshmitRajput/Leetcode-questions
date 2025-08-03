class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        for(int i=0;i<s.size();i++){
            s.push_back(s[0]);
            s.erase(s.begin());

            bool x=true;
            for(int j=0;j<s.length();j++){
                if(s[j]!=goal[j]){
                    x=false;
                    break;
                }

            }
            if(x==true) return true;
        }
        return false;

    }
};