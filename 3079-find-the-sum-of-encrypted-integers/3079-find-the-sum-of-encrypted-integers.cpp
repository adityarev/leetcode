auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        auto enc = [](const int& num) {
            int max_digit = 0;
            int len = 0;
            for (int temp = num; temp > 0; temp /= 10) {
                max_digit = max(max_digit, temp % 10);
                len++;
            }
            int result = 0;
            for (int i = 0; i < len; i++) {
                result = result * 10 + max_digit;
            }
            return result;
        };
        int ans = 0;
        for (const int& num: nums) {
            ans += enc(num);
        }
        return ans;
    }
};