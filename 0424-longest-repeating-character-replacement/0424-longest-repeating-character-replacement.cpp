class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int i = 0;
        int max_freq = 0;
        int ans = 0;
        for (int j = 0; j < s.length(); j++) {
            freq[s[j] - 'A']++;
            max_freq = max(max_freq, freq[s[j] - 'A']);
            int window_len = j - i + 1;
            if (window_len - max_freq > k) {
                freq[s[i] - 'A']--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};