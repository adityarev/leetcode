auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
private:
    const int N = 26;
    vector<vector<int>> letter_max_lens;
    
    int keyof(const char letter) {
        return (int)(letter - 'a');
    }

    void insert_len(const char& letter, const int& len) {
        const int key = keyof(letter);
        letter_max_lens[key].push_back(len);
        sort(letter_max_lens[key].begin(), letter_max_lens[key].end(), greater<int>());
        letter_max_lens[key].pop_back();
    }
    
    int get_longest_thrice(const char& letter) {
        const int key = keyof(letter);
        return max(0,
                   max(letter_max_lens[key][0] - 2,
                       max(letter_max_lens[key][1] == letter_max_lens[key][0] ? letter_max_lens[key][1] - 1 : letter_max_lens[key][1],
                           letter_max_lens[key][2])));
    }

public:
    int maximumLength(string s) {
        letter_max_lens = vector<vector<int>>(N, vector<int>(3, 0));
        for (int l = 0, r = 0; r < s.length(); ) {
            while (++r < s.length() && s[r] == s[l]);
            const int len = r - l;
            insert_len(s[l], len);
            l = r;
        }
        int ans = 0;
        for (char letter = 'a'; letter <= 'z'; letter++) {
            const int letter_longest_thrice = get_longest_thrice(letter);
            ans = max(ans, letter_longest_thrice);
        }
        return ans == 0 ? -1 : ans;
    }
};