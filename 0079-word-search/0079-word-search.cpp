class Solution {
public:
    vector<int> di = {+1, 0, 0, -1};  // Down, Left, Right, Up directions
    vector<int> dj = {0, -1, +1, 0};

    bool solve(int idx, int jdx, int n, int m, vector<vector<bool>> &vis, vector<vector<char>> &board, string &word, int k) {
        if (k == word.size()) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int indexi = idx + di[i];
            int indexj = jdx + dj[i];

            if (indexi >= 0 && indexi < n && indexj >= 0 && indexj < m && !vis[indexi][indexj] && board[indexi][indexj] == word[k]) {
                vis[indexi][indexj] = true;
                if (solve(indexi, indexj, n, m, vis, board, word, k + 1)) return true;
                vis[indexi][indexj] = false;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    vis[i][j] = true;
                    if (solve(i, j, n, m, vis, board, word, 1)) return true;
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
};
