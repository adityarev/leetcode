auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int> counter;
        int min_count = INT_MAX;
        int max_count = 0;
        for (const char& c: word) {
            const int curr_count = ++counter[c];
            min_count = min(min_count, curr_count);
            max_count = max(max_count, curr_count);
        }
        vector<int> prefix_sum(max_count + 1, 0);
        vector<int> prefix_count(max_count + 1, 0);
        for (const auto [k, v]: counter) {
            prefix_sum[v] += v;
            prefix_count[v]++;
        }
        // if (k == 0) {
        //     return word.length() - max_count * (prefix_count[max_count] - prefix_count[max_count-1]);
        // }
        // if (max_count - min_count <= k) {
        //     return 0;
        // }
        // cout << "---\n";
        for (int i = min_count; i <= max_count; i++) {
            prefix_sum[i] += prefix_sum[i-1];
            prefix_count[i] += prefix_count[i-1];
            // cout << i << ": " << prefix_sum[i] << ", " << prefix_count[i] << endl;
        }
        int ans = INT_MAX;
        // cout << "---\n";
        for (int l = min_count, r = min_count + k; r <= max_count; l++, r++) {
            const int r_count = prefix_count.back() - prefix_count[r];
            const int r_sum = prefix_sum.back() - prefix_sum[r];
            const int r_delete = max(0, r_sum - r_count * r);
            const int l_delete = prefix_sum[l-1];
            const int total_delete = l_delete + r_delete;
            ans = min(ans, total_delete);
            // cout << r << ": " << r_count << " " << r_delete << " " << total_delete << endl;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

// 1 2 4 => 3


// 1 2 3 5 5 6
// [0, 1, 2, 3, 3, 5,  6]
// [0, 1, 3, 6, 6, 16, 22]
// 22 - 6 = 18
// 9 - 