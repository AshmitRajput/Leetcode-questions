class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        string conc=goal+goal;
        if(conc.find(s)!=conc.npos){
            return 1;
        }else{
            return 0;
        }

    }
};