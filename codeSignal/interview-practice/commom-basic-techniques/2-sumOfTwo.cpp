//function to check if there is a integer in vec a and a integer in vec b whose sum is v

bool sumOfTwo(std::vector<int> a, std::vector<int> b, int v) {
    map <int, bool> newA;

    for (auto i = a.begin(); i != a.end(); i++) {
        newA[*i] = true;
    }

    for (auto i = b.begin(); i != b.end(); i++) {
        if (newA[v-(*i)]) return true;
    }

    return false;
}
