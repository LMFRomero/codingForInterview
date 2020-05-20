class Solution {
public:
    int countElements(vector<int>& arr) {
        set <int> s;
        int count = 0;
        
        for (int n : arr) {
            s.insert(n);
        }
        
        for (int n : arr) {
            if (s.count(n+1)) count++;
        }
        
        return count;
    }
};
