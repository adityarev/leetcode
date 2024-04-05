class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int r = letters.size() - 1;
        int ans = -1;
        while (l <= r) {
            const int m = l + ((r - l) / 2);
            if (letters[m] > target) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return letters[max(0, ans)];
    }
};