std::string findProfession(int level, int pos) {
    string D = "Doctor", E = "Engineer", ans = E;
    
    if (level == 1)
        return E;

    if (findProfession(level-1, (pos+1)/2) == E)
        return (pos%2) ? E : D;
    
    return (pos%2) ? D : E;
}

