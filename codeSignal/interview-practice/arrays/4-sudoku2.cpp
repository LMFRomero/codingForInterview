bool sudoku2(std::vector<std::vector<char>> grid) {
    int regionX, regionY;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == '.') continue;

            //search in row
            for (int k = 0; k < 9; k++) {
                if (k != j and grid[i][k] == grid[i][j]) return false;
            }

            //search in column
            for (int k = 0; k < 9; k++) {
                if (k != i and grid[k][j] == grid[i][j]) return false;
            }

            //search in region
            regionX = (j / 3)*3;
            regionY = (i / 3)*3;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (regionX + l == j and regionY + k == i) continue;
                    if (grid[regionY + k][regionX + l] == grid[i][j]) return false;
                }
            }
        }
    }
    return true;
}
