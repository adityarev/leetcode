class Solution {
private:
    const int N = 9;
    vector<unordered_set<int>> row_seen;
    vector<unordered_set<int>> col_seen;
    vector<unordered_set<int>> grp_seen;
    vector<vector<int>> empty_cells;
    
    int numof(const char c) {
        return (int)(c - '1');
    }

    int cof(const int num) {
        return (char)('1' + num);
    }

    int gof(const int& r, const int& c) {
        return (r / 3) * 3 + (c / 3);
    }

    void init(vector<vector<char>>& board) {
        row_seen = vector<unordered_set<int>>(N, unordered_set<int>());
        col_seen = vector<unordered_set<int>>(N, unordered_set<int>());
        grp_seen = vector<unordered_set<int>>(N, unordered_set<int>());

        analyze(board);
    }

    void analyze(vector<vector<char>>& board) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (board[r][c] == '.') {
                    empty_cells.push_back({r, c});
                    continue;
                }
                mark(r, c, board[r][c]);
            }
        }
    }

    void mark(const int& r, const int& c, const char& digit) {
        const int num = numof(digit);
        row_seen[r].insert(num);
        col_seen[c].insert(num);
        grp_seen[gof(r, c)].insert(num);
    }

    void unmark(const int& r, const int& c, const char& digit) {
        const int num = numof(digit);
        row_seen[r].erase(num);
        col_seen[c].erase(num);
        grp_seen[gof(r, c)].erase(num);
    }

    bool possible(const int& r, const int& c, const char& num) {
        return !row_seen[r].count(num)
            && !col_seen[c].count(num)
            && !grp_seen[gof(r, c)].count(num);
    }

    bool solve(vector<vector<char>>& board) {
        if (empty_cells.empty()) {
            return true;
        }
        const int r = empty_cells.back()[0];
        const int c = empty_cells.back()[1];
        empty_cells.pop_back();
        for (int num = 0; num < N; num++) {
            if (possible(r, c, num)) {
                board[r][c] = cof(num);
                mark(r, c, board[r][c]);
                if (solve(board)) {
                    return true;
                }
                unmark(r, c, board[r][c]);
                board[r][c] = '.';
            }
        }
        empty_cells.push_back({r, c});
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        init(board);
        solve(board);
    }
};