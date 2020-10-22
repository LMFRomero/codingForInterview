class Solution {
public:
    double distance (int a, int b) {
        return sqrt(a*a+b*b);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        map <double, vector<vector<int>>> m;
        vector<vector<int>> ans;
        vector<double> dist;
        double d;
        
        for (auto v : points) {
            d = distance(v[0], v[1]);
            m[d].push_back(v);
            dist.push_back(d);
        }
        
        sort(dist.begin(), dist.end());
        
        for (int i = 0; i < K;) {
            for (auto v : m[dist[i]]) {
                i++;
                ans.push_back(v);
            }
        }
        
        return ans;
    }
};
