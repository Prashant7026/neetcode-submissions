class Solution {
private:
    void dfsTraversal( int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& fillArr) {
        fillArr[row][col] = true;

        int rowOffset[] = {-1, 0, 1, 0};
        int colOffset[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int newRow = rowOffset[i] + row;
            int newCol = colOffset[i] + col;
            if(newRow < 0 || newRow >= heights.size() || newCol < 0 || newCol >= heights[0].size())     continue;
            
            if(heights[newRow][newCol] >= heights[row][col] && !fillArr[newRow][newCol]) {
                dfsTraversal(newRow, newCol, heights, fillArr);
            }
        }

        return;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacificArr(m, vector<bool>(n, false));
        vector<vector<bool>> atlanticArr(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            dfsTraversal(i, 0, heights, pacificArr);
            dfsTraversal(i, n - 1, heights, atlanticArr);
        }
        for(int j = 0; j < n; j++) {
            dfsTraversal(0, j, heights, pacificArr);
            dfsTraversal(m - 1, j, heights, atlanticArr);
        }

        vector<vector<int>> result;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacificArr[i][j] && atlanticArr[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
