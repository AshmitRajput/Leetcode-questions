class Solution {
public:
    bool isIsomorphic(string s, string t) {
    vector<int> s_code(128);
    vector<int> t_code(128);

    for (int i=0;i<s.length();++i){
      if(s_code[s[i]]!=t_code[t[i]])
        return false;
      s_code[s[i]]=i+1;
      t_code[t[i]]=i+1;
    }
    return true;
    }
};