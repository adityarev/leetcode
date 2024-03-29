class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int even = 0;
        for (const int& num: nums) {
            even += (int)(num % 2 == 0);
            if (even > 1) {
                return true;
            }
        }
        return false;
    }
};