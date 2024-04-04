class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int curr = 0;
        for (const char& c: s) {
            curr += (int)(c == '(');
            ans = max(ans, curr);
            curr -= (int)(c == ')');
        }
        return ans;
    }
};