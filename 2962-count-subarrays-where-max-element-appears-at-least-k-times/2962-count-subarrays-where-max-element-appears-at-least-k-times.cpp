auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_num = 0;
        for (const int& num: nums) {
            max_num = max(max_num, num);
        }
        vector<int> indices;
        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] == max_num) {
                indices.push_back(index);
            }
        }
        long long ans = 0;
        for (int l = 0, r = k - 1; r < indices.size(); l++, r++) {
            const int l_count = indices[l] + 1;
            const int r_count = (r == indices.size() - 1 ? nums.size() : indices[r+1]) - indices[r];
            ans += (long long)l_count * r_count;
        }
        return ans;
    }
};
// 2 * 2 + 4 * 2