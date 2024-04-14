auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end(), [&](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        int ans = 0;
        for (int l = 0, r = 0; r < points.size(); ) {
            ans++;
            while (++r < points.size() && points[r][0] - points[l][0] <= w);
            l = r;
        }
        return ans;
    }
};