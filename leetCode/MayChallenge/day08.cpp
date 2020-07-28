class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        #define INF 1e9+5
        if (coordinates.size() == 2)
            return true;
        
        float d_x = coordinates[1][0]-coordinates[0][0];
        float d_y = coordinates[1][1]-coordinates[0][1];
        float tg_par = (d_x != 0) ? d_y/d_x : INF, tg;
        
        int size = coordinates.size();
    
        for (int i = 2; i < size; i++) {
            float d_x = coordinates[i][0]-coordinates[i-1][0];
            float d_y = coordinates[i][1]-coordinates[i-1][1];
            tg = (d_x != 0) ? d_y/d_x : INF;
            
            if (tg != tg_par)
                return false;
        }
        
        return true;
    }
};
