class Solution {
private:
    bool isPrime(const int& num) {
        if (num < 2) {
            return false;
        }
        for (int div = 2; div * div <= num; div++) {
            if (num % div == 0) {
                return false;
            }
        }
        return true;
    }
    
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int left = -1;
        int right = -1;
        for (int index = 0; index < nums.size(); index++) {
            if (isPrime(nums[index])) {
                if (left == -1) {
                    left = index;
                }
                right = index;
            }
        }
        return right - left;
    }
};