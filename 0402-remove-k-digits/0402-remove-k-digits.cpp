class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";

        for (char c : num) {
            while (!result.empty() && result.back() > c && k > 0) {
                result.pop_back();
                k--;
            }
            result.push_back(c);
        }

        while (k>0&&!result.empty()) {
            result.pop_back();
            k--;
        }
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }
        string finalResult = result.substr(i);
        if (finalResult == "") return "0";
        return finalResult;
    }
};