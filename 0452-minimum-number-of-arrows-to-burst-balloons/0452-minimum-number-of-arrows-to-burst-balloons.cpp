auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        const int N = points.size();
        int ans = 0;
        for (int l = 0; l < N; ) {
            int r = l;
            int min_r = points[l][1];
            while (r < N && points[r][0] <= min_r) {
                min_r = min(min_r, points[r][1]);
                r++;
            }
            ans++;
            l = r;
        }
        return ans;
    }
};
