//function to verify if an array has duplicates

bool containsDuplicates(std::vector<int> a) {
    map <int, bool> valuesInArray;

    for (vector<int>::iterator i = a.begin(); i != a.end(); i++) {
        if (!valuesInArray[*i]) {
            valuesInArray[*i] = true;
            continue;
        }

        return true;
    }

    return false;
}
