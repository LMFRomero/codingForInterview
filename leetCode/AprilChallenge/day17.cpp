class Solution {
public:
    void countIslands (vector<vector<char>>& grid, int i, int j, const int maxI, const int maxJ) {
        if (i < 0 or j < 0 or i >= maxI or j >= maxJ) return;
        if (grid[i][j] != '1') return;
        
        grid[i][j] = '2';
        
        countIslands(grid, i, j-1, maxI, maxJ);
        countIslands(grid, i, j+1, maxI, maxJ);
        countIslands(grid, i-1, j, maxI, maxJ);
        countIslands(grid, i+1, j, maxI, maxJ);
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int size1 = grid.size(), size2 = (size1) ? grid[0].size() : 0;
        
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    countIslands(grid, i, j, size1, size2);
                } 
            }
        }
        return count;
    }
    
   
};
