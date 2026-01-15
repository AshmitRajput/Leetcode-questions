class Solution {
public:
    int rows, cols;
    bool dfs(vector<vector<char>>& board,string &word,int row,int col,int idx){
        if (idx == word.size()) return true;
        if (row < 0 || row >= rows || col < 0 || col >= cols) return false;
        if (board[row][col] != word[idx]) return false;
        char temp = board[row][col];
        board[row][col] = '#';
        bool found =
            dfs(board, word, row+1, col, idx+1)||dfs(board, word, row-1, col, idx+1)||dfs(board, word, row, col+1, idx+1)||dfs(board, word, row, col-1, idx+1);
        board[row][col]=temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
