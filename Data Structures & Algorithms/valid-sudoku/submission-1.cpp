class Solution {
public:
    bool checkRowUnique(vector<vector<char>> board) {
        unordered_set<int> hs;

        for(auto i: board) {
            for(auto j: i) {
                if(hs.find(j) != hs.end()) {
                    return false;
                } else {
                    if(j != '.') {
                        hs.insert(j);
                    }
                }
            }
            hs.clear();
        }

        return true;
    }

    bool checkColUnique(vector<vector<char>> board) {
        unordered_set<int> hs;
        int col = board[0].size();
        int row = board.size();
        for(int j = 0; j < col; j++) {
            for(int i = 0; i < row; i++) {
                char element = board[i][j];
                if(hs.find(element) != hs.end()) {
                    return false;
                } else {
                    if(element != '.') {
                        hs.insert(element);
                    }
                }
            }
            hs.clear();
        }

        return true;
    }

    bool checkBoxUnique(vector<vector<char>> board) {
        int startRow = 0, endRow = startRow + 2;
        int startCol = 0, endCol = startCol + 2;
        int boxSize = 9;
        unordered_set<int> hs;

        while(boxSize > 0) {
            for(int i = startRow; i <= endRow; i++) {
                for(int j = startCol; j <= endCol; j++) {
                    char element = board[i][j];
                    if(hs.find(element) != hs.end()) {
                        return false;
                    } else {
                        if(element != '.') {
                            hs.insert(element);
                        }
                    }
                }
            }
            hs.clear();
            if(endRow == 8) {
                startRow = 0;
                endRow = startRow + 2;
                startCol = endCol + 1;
                endCol = startCol + 2;
            } else {
                startRow = endRow + 1;
                endRow = startRow + 2;
            }

            boxSize--;
        }
        
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        if (!checkRowUnique(board)) {
            return false;
        } else if(!checkColUnique(board)) {
            return false;
        } else if(!checkBoxUnique(board)) {
            return false;
        }

        return true;
    }
};
