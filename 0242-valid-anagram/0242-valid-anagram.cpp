class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int>arr1(26,0);
        vector<int>arr2(26,0);
        for(int i=0;i<s.size();i++){
            arr1[int(s[i])-97]++;
            arr2[int(t[i])-97]++;
        }
        if(arr1==arr2) return true;
        else{
            return false;
        }
    }
};