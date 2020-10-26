class Solution {
public:
    void swap (char& a, char& b) {
        char t;
        t = a;
        a = b;
        b = t;
    }
    
    void reverseString(vector<char>& s) {
        int w = s.size();
        int h = w/2;
        
        for (int i = 0; i < h; i++) {
            swap(s[i], s[w-1-i]);
        }
    }
};
