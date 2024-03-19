auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_map<char, unordered_map<char, bool>> seen;
        for (int i = 1; i < s.length(); i++) {
            if (s[i-1] == s[i] || seen[s[i]][s[i-1]]) {
                return true;
            }
            seen[s[i-1]][s[i]] = true;
        }
        return false;
    }
};