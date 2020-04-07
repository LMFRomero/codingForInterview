bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
    map <char, int> m;
    int sum1 = 0;
    int maxSize = max(crypt[0].size(), crypt[1].size());
    int size0 = crypt[0].size();
    int size1 = crypt[1].size();

    int sum2 = 0;
    int size2 = crypt[2].size();

    for (auto v : solution) m[v[0]] = ((int)v[1])-48;

    if (size0 > 1) {
        if (m[(crypt[0])[0]] == 0) return false;
    }

    if (size1 > 1) {
        if (m[(crypt[1])[0]] == 0) return false;
    }

    if (size2 > 1) {
        if (m[(crypt[2])[0]] == 0) return false;
    }


    for (int i = 0; i < maxSize; i++) {
        sum1 += ((m[(crypt[0])[size0-1-i]]) + (m[(crypt[1])[size1-1-i]])) * (pow(10, i));
    }

    for (int i = 0; i < size2; i++) {
        sum2 += (m[(crypt[2])[size2-1-i]]) * (pow(10, i));
    }

    return (sum1 == sum2);
    
}
