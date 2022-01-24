int lis(vector<int> x) {
    vector<int> y;
    for (int i : x) {
        auto iter = upper_bound(y.begin(), y.end(), i);
        if (iter == y.end()) {
            y.emplace_back(i);
        } else {
            *iter = i;
        }
    }
    return (int) y.size();
}
