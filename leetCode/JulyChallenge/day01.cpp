class Solution {
public:
    int arrangeCoins(int n) {
        int counter = 0;
        for (int i = 1; true; i++) {
            n -= i;
            if (n < 0) return counter;
            counter++;
        }
    }
};
