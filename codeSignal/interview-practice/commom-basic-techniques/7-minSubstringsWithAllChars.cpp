std::string minSubstringWithAllChars(std::string s, std::string t) {
    set <char> unique;
    set <char> newT;
    map <char, int> countChar;

    for (char c : t) newT.insert(c);

    int maxLow = 0, maxHigh = -1;
    int low = -1, high = -1;

    for (int i = 0; i < s.size(); i++) {
        if (!(newT.count(s[i]))) continue;
        
        unique.insert(s[i]);
        countChar[s[i]]++;
        high = i;
        if (low == -1) low = i;
        else if (s[i] == s[low]) {
            while (!(newT.count(s[low])) or countChar[s[low]] > 1) {
                if (newT.count(s[low]))countChar[s[low]]--;
                low++;
            } 
        }

        if (unique.size() >= t.size()) {
            if ((high - low < maxHigh - maxLow) or maxHigh == -1) {
                maxHigh = high;
                maxLow = low;
            }
        }
    }

    return s.substr(maxLow, maxHigh-maxLow+1);
}
