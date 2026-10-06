class Solution {
public:
    typedef long long ll;
    string toHex(int num) {

        // For num<0, num= 2^32+num.
        vector<char> hexDigits = {'0', '1', '2', '3', '4', '5', '6', '7',
                                  '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

        string ans = "";
        ll k = num;
        if (num < 0)
            k = pow(2, 32) + k;
        if (k == 0)
            return "0";
        while (k != 0) {
            int rem = k % 16;
            int q = k / 16;
            k = q;
            ans += hexDigits[rem];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};