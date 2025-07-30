class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        vector<char> uniqueChars;
        for (auto& keyValue:mpp) {
            uniqueChars.push_back(keyValue.first);
        }
        sort(uniqueChars.begin(), uniqueChars.end(), [&](char a, char b) {
            return mpp[a]>mpp[b];
        });
        string result;
        for (char ch : uniqueChars) {
            result += string(mpp[ch], ch);
        }
        return result;
    }
};