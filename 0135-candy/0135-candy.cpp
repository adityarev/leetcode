auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        vector<int> indices;
        for (int i = 0; i < N; i++) {
            indices.push_back(i);
        }
        sort(indices.begin(), indices.end(), [&](const int& a, const int& b) {
            return ratings[a] < ratings[b];
        });
        vector<int> candies(N, 0);
        int ans = 0;
        for (const int& index: indices) {
            int candy = 1;
            if (index != 0 && ratings[index] > ratings[index-1]) {
                candy = max(candy, candies[index-1] + 1);
            }
            if (index != N-1 && ratings[index] > ratings[index+1]) {
                candy = max(candy, candies[index+1] + 1);
            }
            candies[index] = candy;
            ans += candy;
        }
        return ans;
    }
};
