
class Solution {
public:
    tuple<int, bool, int> parser(string s) {
        int k = 0, i = 0, n = s.length();

        while (i < n && s[i] != ':') {
            k = k * 10 + (s[i] - '0');
            i++;
        }
        i++;

        bool start = (s.substr(i, 5) == "start");

        while (i < n && s[i] != ':') {
            i++;
        }
        i++;

        int time = 0;
        while (i < n) {
            time = time * 10 + (s[i] - '0');
            i++;
        }

        return {k, start, time};
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> s;
        vector<int> ans(n, 0);
        int prev = 0;
        for (string log : logs) {
            auto [k, start, time] = parser(log);
            if (start) {
                if (!s.empty()) {
                    ans[s.top().first] += time - prev;
                }
                s.push({k, time});
                prev = time;
            } else {
                ans[s.top().first] += time - prev + 1;
                s.pop();
                prev = time + 1;
            }
        }
        return ans;
    }
};