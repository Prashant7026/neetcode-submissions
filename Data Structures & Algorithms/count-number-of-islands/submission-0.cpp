class Solution {
vector<vector<char>> bigGrid;

void bfsTraversal(int row, int col) {
    if(bigGrid[row][col] == '0' || bigGrid[row][col] == '#')    return;

    bigGrid[row][col] = '#';

    int rowOffset[] = {-1, 0, 1, 0};
    int colOffset[] = {0, 1, 0, -1};

    for(int i = 0; i < 4; i++) {
        int newRow = row + rowOffset[i];
        int newCol = col + colOffset[i];
        if(newRow < 0 || newCol < 0 || newRow >= bigGrid.size() || newCol >= bigGrid[0].size()){
            continue;
        }
        bfsTraversal(newRow, newCol);
    }

    return;
}

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        bigGrid = grid;

        for(int i = 0; i < bigGrid.size(); i++) {
            for(int j = 0; j < bigGrid[0].size(); j++) {
                if(bigGrid[i][j] == '1') {
                    bfsTraversal(i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};
