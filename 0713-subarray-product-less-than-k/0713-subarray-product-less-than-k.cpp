auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
private:
    int sn(const int n) {
        return (long long)(n * (n + 1)) / 2;
    }
    
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) {
            return 0;
        }
        const int len = nums.size();
        int curr = 1;
        int prev_r = -1;
        int ans = 0;
        for (int l = 0, r = -1; r < len; ) {
            while (++r < len) {
                curr *= nums[r];
                if (curr >= k) {
                    break;
                }
            }
            const int n = r - l;
            const int ni = max(0, prev_r - l);
            ans += sn(n) - sn(ni);
            while (l <= r && curr >= k) {
                curr /= nums[l++];
            }
            prev_r = r;
        }
        return ans;
    }
};