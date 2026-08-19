class Solution {
public:
    int m, n;
    
    bool dfs(vector<vector<char>>& board, string& word,
             int row, int col, int index) {
        
        // Entire word found
        if (index == word.size()) {
            return true;
        }

        // Out of bounds or character doesn't match
        if (row < 0 || row >= m ||
            col < 0 || col >= n ||
            board[row][col] != word[index]) {
            return false;
        }

        // Mark cell as visited
        char original = board[row][col];
        board[row][col] = '#';

        // Explore 4 directions
        bool found =
            dfs(board, word, row + 1, col, index + 1) ||
            dfs(board, word, row - 1, col, index + 1) ||
            dfs(board, word, row, col + 1, index + 1) ||
            dfs(board, word, row, col - 1, index + 1);

        // Backtrack
        board[row][col] = original;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};