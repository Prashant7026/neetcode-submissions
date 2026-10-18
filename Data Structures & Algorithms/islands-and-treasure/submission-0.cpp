class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        int rowOffset[] = {-1, 0, 1, 0};
        int colOffset[] = {0, 1, 0, -1};
        
        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int newRow = row + rowOffset[i];
                int newCol = col + colOffset[i];

                if(newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size())   continue;
            
                // If INT_MAX is already replaced that's mean it got the shortest distance.
                // Visit only unvisited land cells
                if(grid[newRow][newCol] != INT_MAX)     continue;
            
                grid[newRow][newCol] = grid[row][col] + 1;
                q.push({newRow, newCol});
            }
        }
    }
};
