auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> counter;
        for (const int& task: tasks) {
            counter[task]++;
        }
        priority_queue<int> pq;
        for (const auto& it: counter) {
            pq.push(it.second);
        }
        int ans = 0;
        while (!pq.empty()) {
            queue<int> q;
            for (int i = 0; !pq.empty() && i <= n; i++) {
                q.push(pq.top());
                pq.pop();
            }
            const int q_size = q.size();
            while (!q.empty()) {
                const int curr_count = q.front() - 1;
                if (curr_count > 0) {
                    pq.push(curr_count);
                }
                q.pop();
            }
            ans += (n + 1);
            if (pq.empty()) {
                ans -= (n + 1) - q_size;
            }
        }
        return ans;
    }
};