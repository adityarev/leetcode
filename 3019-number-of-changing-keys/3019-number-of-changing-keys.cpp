class Solution {
public:
    int countKeyChanges(string s) {
        int ans = 0;
        for (int i = 1; i < s.length(); i++) {
            ans += (int)(tolower(s[i]) != tolower(s[i-1]));
        }
        return ans;
    }
};