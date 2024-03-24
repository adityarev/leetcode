class Solution {
public:
    int maximumLengthSubstring(string s) {
        const int len = s.length();
        int l = -1;
        int r = 0;
        unordered_map<char,int> counter;
        int ans = 0;
        while (r < len) {
            counter[s[r]]++;
            while (counter[s[r]] > 2) {
                counter[s[++l]]--;
            }
            ans = max(ans, r - l);
            r++;
        }
        return ans;
    }
};