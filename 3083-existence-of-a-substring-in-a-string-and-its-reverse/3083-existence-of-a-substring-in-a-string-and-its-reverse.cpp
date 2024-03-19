auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
private:
    const int N_ALPH = 26;
    
    int keyof(const char c) {
        return (int)(c - 'a');
    }
    
public:
    bool isSubstringPresent(string s) {
        vector<vector<bool>> seen(N_ALPH, vector<bool>(N_ALPH, false));
        for (int i = 1; i < s.length(); i++) {
            const int l = keyof(s[i-1]);
            const int r = keyof(s[i]);
            if (l == r || seen[r][l]) {
                return true;
            }
            seen[l][r] = true;
        }
        return false;
    }
};