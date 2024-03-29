auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maximumLength(string s) {
        const int len = s.length();
        for (int ans = len - 2; ans > 0; ans--) {
            unordered_map<string,int> counter;
            unordered_map<char,int> freq;
            string str = "";
            for (int i = 0; i < ans - 1; i++) {
                str += s[i];
                freq[s[i]]++;
            }
            for (int l = 0, r = ans - 1; r < len; l++, r++) {
                str += s[r];
                freq[s[r]]++;
                if (++counter[str] == 3 && freq.size() == 1) {
                    return ans;
                }
                str = str.substr(1);
                if (--freq[s[l]] == 0) {
                    freq.erase(s[l]);
                }
            }
        }
        return -1;
    }
};