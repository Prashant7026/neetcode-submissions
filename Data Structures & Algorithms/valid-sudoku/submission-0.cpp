class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> hs;
        // For row
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(hs.find(board[i][j] - '0') != hs.end()){
                    return false;
                }
                if(isdigit(board[i][j]))    hs.insert(board[i][j] - '0');
            }
            hs.clear();
        }

        // For col
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(hs.find(board[j][i] - '0') != hs.end()){
                    return false;
                }
                if(isdigit(board[j][i]))    hs.insert(board[j][i] - '0');
            }
            hs.clear();
        }

        // For 3 x 3 sub-boxes
        int rowStart = 0, rowEnd = 3;
        for(int k = 0; k < 3; k++){
            int colStart = 0, colEnd = 3;
            for(int i = rowStart; i < rowEnd; i++){
                for(int j = colStart; j < colEnd; j++){
                    if(hs.find(board[i][j] - '0') != hs.end()){
                        return false;
                    }
                    if(isdigit(board[i][j]))    hs.insert(board[i][j] - '0');
                }
                // hs.clear();
            }

            hs.clear();
            for(int i = rowStart; i < rowEnd; i++){
                for(int j = colStart+3; j < colEnd+3; j++){
                    int val = board[i][j] - '0';
                    if(hs.find(val) != hs.end()){
                        cout<<"njfsjfsdjkfdsjkfsdffdsfsdfdsfsdf";
                        return false;
                    }
                    if(isdigit(board[i][j]))    hs.insert(board[i][j] - '0');
                }
                // hs.clear();
            }

            hs.clear();
            for(int i = rowStart; i < rowEnd; i++){
                for(int j = colStart+6; j < colEnd+6; j++){
                    if(hs.find(board[i][j] - '0') != hs.end()){
                        return false;
                    }
                    if(isdigit(board[i][j]))    hs.insert(board[i][j] - '0');
                }
                // hs.clear();
            }
            
            hs.clear();
            rowStart += 3;
            rowEnd += 3;
        }

        return true;
    }
};
