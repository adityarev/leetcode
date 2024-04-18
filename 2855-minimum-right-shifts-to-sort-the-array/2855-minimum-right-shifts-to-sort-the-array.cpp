class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        const int len = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        int min_num = INT_MAX;
        int min_index = -1;
        for (int i = 0; i < len; i++) {
            if (nums[i] < min_num) {
                min_num = nums[i];
                min_index = i;
            }
            pq.push(nums[i]);
        }
        for (int i = 0; i < len; i++) {
            if (nums[(i + min_index) % len] != pq.top()) {
                return -1;
            }
            pq.pop();
        }
        return (len - min_index) % len;
    }
};