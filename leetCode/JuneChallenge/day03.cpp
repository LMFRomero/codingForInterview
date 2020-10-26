class Solution {
public:
    static bool cmp (vector<int> a, vector<int> b) {
        return abs(a[0]-a[1]) < abs(b[0]-b[1]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int a, b, ans;
        int N = costs.size()/2;
        a = b = ans = 0;
    
        sort(costs.rbegin(), costs.rend(), cmp);

        for (auto v : costs) {
            if (a == N) {
                ans += v[1];
                b++;
            }
            else if (b == N) {
                ans += v[0];
                a++;
            }
            else {
                if (v[0] < v[1]) {
                    ans += v[0];
                    a++;
                }
                else {
                    ans += v[1];
                    b++;
                }
            }
        }
        
        return ans;
    }
};
