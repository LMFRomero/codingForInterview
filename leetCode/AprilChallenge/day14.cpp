class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int shiftCount = 0;
        string answer = "";
        
        for (auto x : shift) {
            if (x[0]) shiftCount += x[1];
            else shiftCount -= x[1];
        }
        int size = s.size();
        
        for (int i = 0; i < size; i++) {
            int index = (i-shiftCount)%size;
            index = (index < 0) ? index+size : index;
            answer += s[index];
        }
        
        return answer;
    }
};
