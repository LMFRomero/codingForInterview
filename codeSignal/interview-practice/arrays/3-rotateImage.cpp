std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
    int N = a.size();
    int tmp;

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (N/2); j++) {
            tmp = a[i][j];
            a[i][j] = a[i][N-j-1];
            a[i][N-j-1] = tmp;
        }
    }

    return a;
}

