class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char,int> smap;
        map<char,int> tmap;
        for(int i=0;i<s.size();i++){
            smap[s[i]]++;tmap[t[i]]++;
        }
        for(auto &i:smap){
            if(tmap[i.first]!=i.second){
                return false;
            }
        }
        return true;
    }
};