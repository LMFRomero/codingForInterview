string add_brackets (string word, int part_size, int index) {
    string s = "";
    int size = word.size();

    for (int i = 0; i < index; i++) {
        s += word[i];
    }

    s += '[';

    for (int i = 0; i < part_size; i++) {
        s += word[index+i];
    }

    s += ']';

    for (int i = index+part_size; i < size; i++) {
        s += word[i];
    }

    return s;
}

std::vector<std::string> findSubstrings(std::vector<std::string> words, std::vector<std::string> parts) {
    vector <string> v;
    set <string> s;
    bool found;

    for (string p : parts) s.insert(p);

    for (string w : words) {
        found = false;
        for (int len = 5; len; len--) {
            for (int i = 0; i+len <= w.size(); i++) {
                if (s.count(w.substr(i, len))) {
                    found = true;
                    v.push_back(add_brackets(w, len, i));
                    break;
                }
            }
            if (found) break;
        }
        if (!found) v.push_back(w);
    }    

    return v;
}
