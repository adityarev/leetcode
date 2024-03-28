auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        const int len = nums.size();
        int ans = 0;
        unordered_map<int,int> counter;
        for (int l = 0, r = -1; r < len; ) {
            while (++r < len) {
                if (++counter[nums[r]] > k) {
                    break;
                }
            }
            ans = max(ans, r - l);
            if (r < len) {
                while (l <= r && counter[nums[r]] > k) {
                    counter[nums[l++]]--;
                }
            }
        }
        return ans;
    }
};