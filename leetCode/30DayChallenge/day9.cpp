lass Solution {
public:
    bool backspaceCompare(string S, string T) {
        int countS = 0;
        int countT = 0;
        auto itS = S.rbegin();
        auto itT = T.rbegin();
        
        while (itS != S.rend() and (*itS == '#' or countS)) {
            if (*itS == '#') countS++;
            else countS--;
            itS++;
        }
           
        while (itT != T.rend() and (*itT == '#' or countT)) {
            if (*itT == '#') countT++;
            else countT--;
            itT++;
        }
        
        while (itS != S.rend() and itT != T.rend()) {            
            if (*itS != *itT) return false;
            
            itS++;
            itT++;
            
            while (itS != S.rend() and (*itS == '#' or countS)) {
                if (*itS == '#') countS++;
                else countS--;
                itS++;
            }
            
            while (itT != T.rend() and (*itT == '#' or countT)) {
                if (*itT == '#') countT++;
                else countT--;
                itT++;
            }
        }
        
        if (itS == S.rend() and itT == T.rend()) return true;
        return false;
    }
};
