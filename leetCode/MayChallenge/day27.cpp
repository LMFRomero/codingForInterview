class Solution {
    vector<vector<int>> edges;
    bool ok = true;
    vector<int> col;
    void dfs (int a, int color) {
        for (int b : edges[a]) {
            if (col[b] == -1) {
                col[b] = color^1;
                dfs(b, col[b]);
            }
            else if (col[b] == color){
                ok = false;
            }
        }
    }
    
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        col.clear();
        col.resize(N+1, -1);
        edges.clear();
        edges.resize(N+1);
        
        for (vector<int> e : dislikes) {
            int a = e[0];
            int b = e[1];
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        
        ok = true;
        
        for (int a = 1; a <= N; a++) {
            if (col[a] == -1) {
                col[a] = 0;
                dfs(a, 0);
            }
        }
        
        return ok;
    }
};
