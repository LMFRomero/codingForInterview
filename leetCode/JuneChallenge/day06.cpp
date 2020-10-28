class Solution {
public:
    map <int, bool> occupiedPos;
    
    int getNewStart (int size) {
        for (int i = 0; i < size; i++)
            if (occupiedPos[i] == false)
                return i;
        
        return -1;
    }
    
    int indexAfterJump (int currentStart, int jump) {
        int jumped = 0;
        
        for (int i = 0; i < jump; i++) {
            if (occupiedPos[jumped + currentStart])
                i--;
            jumped++;
        }
        
        while (occupiedPos[jumped + currentStart])
            jumped++;
        
        return currentStart+jumped;
    }
    
    static bool cmp (vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        
        int currentStart = 0;
        int currentHeight = -1;
        int size = people.size();
        int nextOcup;
        vector<vector<int>> ans(size);
        vector<int> tmp;
        
        for (int i = 0; i < size; i++) {
            if (people[i][0] != currentHeight) {
                currentHeight = people[i][0];
                for(int t : tmp) {
                    occupiedPos[t] = true;
                }
                tmp.clear();
                
                currentStart = getNewStart(size);
            }
            int nextOcup = indexAfterJump(currentStart, people[i][1]);
            tmp.push_back(nextOcup);
            ans[nextOcup] = people[i];
        }
    
        return ans;
    }
};
