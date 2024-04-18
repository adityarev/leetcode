class Solution {
private:
    enum Type {
        WATER = 0,
        LAND
    };
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int R = grid.size();
        const int C = grid[0].size();
        int ans = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == LAND) {
                    ans += 4;
                    if (r > 0) {
                        ans -= grid[r-1][c];
                    }
                    if (r < R - 1) {
                        ans -= grid[r+1][c];
                    }
                    if (c > 0) {
                        ans -= grid[r][c-1];
                    }
                    if (c < C - 1) {
                        ans -= grid[r][c+1];
                    }
                }
            }
        }
        return ans;
    }
};