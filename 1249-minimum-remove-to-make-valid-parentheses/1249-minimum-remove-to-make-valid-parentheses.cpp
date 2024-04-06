auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> indices;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '(' && s[i] != ')') {
                continue;
            }
            if (indices.size() == 0) {
                indices.push_back(i);
            } else {
                if (s[indices.back()] == '(' && s[i] == ')') {
                    indices.pop_back();
                } else {
                    indices.push_back(i);
                }
            }
        }
        vector<bool> removed(s.length(), false);
        for (const int& index: indices) {
            removed[index] = true;
        }
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (!removed[i]) {
                ans += s[i];
            }
        }
        return ans;
    }
};