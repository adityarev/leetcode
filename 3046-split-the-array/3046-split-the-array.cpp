class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int> counter;
        for (const int& num: nums) {
            if (++counter[num] > 2) {
                return false;
            }
        }
        return true;
    }
};