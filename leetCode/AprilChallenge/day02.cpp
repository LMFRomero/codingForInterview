class Solution {
public:
    int getTheSum (int n) {
        int sum = 0;
        int digit;
        
        while (n) {
            digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        
        return sum;
    }
    
    bool isHappy(int n) {
        set <int> s;
        
        while (true) {
            n = getTheSum(n);
            if (n == 1) return true;
            if (s.count(n) == 1) return false;
            
            s.insert(n);
        }
    }
};
