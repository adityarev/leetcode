auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<int>());
        int pointer = 0;
        for (int n: apple) {
            while (n > 0) {
                if (capacity[pointer] == 0) {
                    pointer++;
                }
                const int min_take = min(n, capacity[pointer]);
                capacity[pointer] -= min_take;
                n -= min_take;
            }
        }
        return pointer + 1;
    }
};