class Solution {
/*
private:
    bool wordMatched(vector<vector<char>>& arr, string word, vector<bool>& visitRow, vector<bool>& visitCol, int i, int j, int count) {
        if(count == word.size() - 1)    return true;

        visitRow[i] = true;
        visitCol[j] = true;
        
        bool top, bottom, left, right;
        if(i > 0) {
            if(word[count] == arr[i-1][j] && (!visitRow[i-1] || !visitCol[j]))    top = wordMatched(arr, word, visitRow, visitCol, i - 1, j, count + 1);
        }
        if(i < arr.size() - 1) {
            if(word[count] == arr[i+1][j] && (!visitRow[i+1] || !visitCol[j]))    bottom = wordMatched(arr, word, visitRow, visitCol, i + 1, j, count + 1);
        }
        if(j > 0) {
            if(word[count] == arr[i][j-1] && (!visitRow[i] || !visitCol[j-1]))    left = wordMatched(arr, word, visitRow, visitCol, i, j - 1, count + 1);
        }
        if(j < arr[0].size() - 1) {
            if(word[count] == arr[i][j+1] && (!visitRow[i] || !visitCol[j+1]))    right = wordMatched(arr, word, visitRow, visitCol, i, j + 1, count + 1);
        }

        return top || bottom || left || right;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    vector<bool> visitRow(board.size(), false);
                    vector<bool> visitCol(board[0].size(), false);
                    bool matched = wordMatched(board, word, visitRow, visitCol, i, j, 1);
                    if(matched) return true;
                }
            }
        }

        return false;
    }
    */

    private:
    bool wordMatched(vector<vector<char>>& board, string& word,
                     vector<vector<bool>>& visited,
                     int i, int j, int count) {

        // All characters matched
        if (count == word.size()) {
            return true;
        }

        // Out of bounds
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size()) {
            return false;
        }

        // Current cell is invalid
        if (visited[i][j] || board[i][j] != word[count]) {
            return false;
        }

        // Mark current cell
        visited[i][j] = true;

        // Explore all four directions
        bool found =
            wordMatched(board, word, visited, i - 1, j, count + 1) || // Top
            wordMatched(board, word, visited, i + 1, j, count + 1) || // Bottom
            wordMatched(board, word, visited, i, j - 1, count + 1) || // Left
            wordMatched(board, word, visited, i, j + 1, count + 1);   // Right

        // Backtrack: restore state
        visited[i][j] = false;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(
            rows, vector<bool>(cols, false)
        );

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (wordMatched(board, word, visited, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
