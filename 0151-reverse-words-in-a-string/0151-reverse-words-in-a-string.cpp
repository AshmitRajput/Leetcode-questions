class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int last=s.length()-1;

        while (last>=0) {
            while (last>=0&&s[last] ==' ') {
                last--;
            }
            if (last<0) break;
            int j=last;

            while (j>=0 && s[j]!=' ') j--;
            string word = s.substr(j+1, last-j);

            if (!result.empty()) result+=" ";
            result += word;
            last=j;
        }
        return result;
    }
};