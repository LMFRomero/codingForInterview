//constant space solution
int firstDuplicate(std::vector<int> a) {
    
    for (int i = 0; i < a.size(); i++) {
        if (a[abs(a[i]) - 1] < 0) return abs(a[i]);

        a[abs(a[i]) - 1] *= -1;
    }

    return -1;
}
