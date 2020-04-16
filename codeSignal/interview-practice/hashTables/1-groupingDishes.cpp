std::vector<std::vector<std::string>> groupingDishes(std::vector<std::vector<std::string>> dishes) {
    map <string, vector<string>> ingredients;
    for (auto vecString : dishes) {
        for (int i = 1; i < vecString.size(); i++) {
            ingredients[vecString[i]].push_back(vecString[0]);
        }
    }
    vector<vector<string>> answer;

    for (auto it = ingredients.begin(); it != ingredients.end(); it++) {
        vector<string> tmp = it->second;
        if (tmp.size() < 2) continue;
        sort(tmp.begin(), tmp.end());
        auto itTemp = tmp.begin();
        tmp.insert(itTemp, it->first);
        answer.push_back(tmp); 
    }

    return answer;
}
