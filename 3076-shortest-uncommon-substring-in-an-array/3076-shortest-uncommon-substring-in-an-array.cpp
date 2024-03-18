auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
private:
    int N;
    vector<vector<string>> substrs;
    unordered_map<string,int> counter;

    void init(vector<string>& arr) {
        N = arr.size();
        substrs = vector<vector<string>>(N);
        for (int i = 0; i < N; i++) {
            set<string> unique;
            for (int l = 0; l < arr[i].length(); l++) {
                string substr = "";
                for (int r = l; r < arr[i].length(); r++) {
                    substr += arr[i][r];
                    unique.insert(substr);
                }
            }
            for (const string& substr: unique) {
                substrs[i].push_back(substr);
                counter[substr]++;
            }
            sort(substrs[i].begin(), substrs[i].end(), [](const string& a, const string& b) {
                return a.length() == b.length() ? a < b : a.length() < b.length();
            });
        }
    }

    void update_counter(const int& i, const int inc) {
        for (const string& substr: substrs[i]) {
            counter[substr] += inc;
        }
    }

public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        init(arr);
        vector<string> ans;
        for (int i = 0; i < N; i++) {
            update_counter(i, -1);
            for (const string& substr: substrs[i]) {
                if (counter[substr] == 0) {
                    ans.push_back(substr);
                    break;
                }
            }
            if (ans.size() == i) {
                ans.push_back("");
            }
            update_counter(i, 1);
        }
        return ans;
    }
};