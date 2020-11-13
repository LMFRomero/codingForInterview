class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long t = 1;
        
        while (t < n)
            t *= 2;
        
        return t == n;
    }
};
