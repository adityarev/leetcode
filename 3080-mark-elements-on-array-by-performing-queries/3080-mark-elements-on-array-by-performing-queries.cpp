auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        auto comp = [&](const int& b, const int& a) {
            return nums[a] == nums[b] ? a < b : nums[a] < nums[b];
        };
        const int N = nums.size();
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        long long sum = 0LL;
        for (int index = 0; index < N; index++) {
            pq.push(index);
            sum += nums[index];
        }
        vector<bool> marked(N, false);
        vector<long long> ans;
        for (const vector<int>& query: queries) {
            const int index = query[0];
            if (!marked[index]) {
                sum -= nums[index];
                marked[index] = true;
            }
            int k = query[1];
            while (!pq.empty() && k > 0) {
                if (!marked[pq.top()] != 0) {
                    sum -= nums[pq.top()];
                    marked[pq.top()] = true;
                    k--;
                }
                pq.pop();
            }
            ans.push_back(sum);
        }
        return ans;
    }
};