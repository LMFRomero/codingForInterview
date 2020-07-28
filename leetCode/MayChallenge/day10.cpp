class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<set<int>> v(N);
        vector<int> possibilities;
        int judge = -1;
        int count1 = 0;
        int count2 = 0;
        
        for (auto vec : trust)
            v[vec[0]-1].insert(vec[1]-1);
        
        for (int i = 0; i < N; i++) {
            if (v[i].empty())
                possibilities.push_back(i);
        }
        
        for (int n : possibilities) {
            count1 = 0;
            for (int i = 0; i < N; i++) {
                if (i == n)
                    continue;

                auto it = v[i].find(n);
                if (it == v[i].end())
                    break;
                else
                    count1++;
            }
            
            if (count1 == N-1) {
                count2++;
                judge = n;
            } 
        }
        
        return count2 == 1 ? judge+1 : -1;
    }
};
