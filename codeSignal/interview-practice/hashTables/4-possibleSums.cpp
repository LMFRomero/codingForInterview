int possibleSums(std::vector<int> coins, std::vector<int> quantity) {
    unordered_set <int> s;
    s.insert(0);

    for (int i = 0; i < quantity.size(); i++) {
        auto tmp = s;
        for (int j = 1; j <= quantity[i]; j++) {
            for (int sum : tmp) 
                s.insert(sum+coins[i]*j);
        }
    }
    
    return s.size()-1; //different from zero
}
