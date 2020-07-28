class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set <char> s;
        int count = 0;
        
        for (char c : J)
            s.insert(c);
        
        for (char c : S) {
            if (s.find(c) != s.end())
                count++;
        }
        
        return count;
    }
};
