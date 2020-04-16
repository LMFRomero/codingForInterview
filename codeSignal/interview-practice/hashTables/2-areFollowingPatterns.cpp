bool areFollowingPatterns(std::vector<std::string> strings, std::vector<std::string> patterns) {
    int size = strings.size();
    if (size != patterns.size()) return false;

    map <string, string> m;
    map <string, string> m2;
    for (int i = 0; i < size; i++) {
        if(m.find(patterns[i]) == m.end()) m[patterns[i]] = strings[i];
        else if (m[patterns[i]] != strings[i]) return false;

        if(m2.find(strings[i]) == m2.end()) m2[strings[i]] = patterns[i];
        else if (m2[strings[i]] != patterns[i]) return false;
    }

    return true;
}
