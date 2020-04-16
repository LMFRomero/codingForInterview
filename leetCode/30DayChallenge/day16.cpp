class Solution {
public:
    bool checkValidString(string s) {
        int countPar = 0;
        int countAstOpen = 0;
        int countAstClose = 0;
        
        for (char c : s) {
            if (c == '(') countPar++;
            else if (c == '*') {
                countAstOpen++;
                countAstClose++;
            }
            else {
                countPar--;
                if (countPar < 0) {
                    if (countAstOpen > 0) {
                        countAstOpen--;
                        countPar++;
                    }
                    else return false;
                }
                else countAstClose = min(countAstClose, countPar);
            }
            cout << countPar << " ";
        }

        if (countAstClose >= countPar) return true;
        return false;
    }
};
