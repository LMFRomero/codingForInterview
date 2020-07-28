class Solution {
public:
    vector<vector<bool>> visited;
    void fill (vector<vector<int>>& image, vector<vector<bool>> visited, const int startColor, const int newColor, int i, int j) {
        if (i < 0 or j < 0 or i >= image.size() or j >= image[0].size())
            return;
        
        if (image[i][j] != startColor)
            return;
        
        if (visited[i][j] == true)
            return;
        
        visited[i][j] = true;
        image[i][j] = newColor;
        
        fill(image, visited, startColor, newColor, i+1, j);
        fill(image, visited, startColor, newColor, i-1, j);
        fill(image, visited, startColor, newColor, i, j+1);
        fill(image, visited, startColor, newColor, i, j-1);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> visited (image.size(), vector<bool>(image[0].size(), false));
        fill(image, visited, image[sr][sc], newColor, sr, sc);
        return image;
    }
};
