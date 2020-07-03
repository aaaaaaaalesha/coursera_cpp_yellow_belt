// Copyright 2020 aaaaaaaalesha

#include <iostream>
#include <vector>

double MeanTemp(const std::vector<int> &tempDB) {
    int64_t sum = 0;
    int64_t count = 0;
    for (const auto &e: tempDB) {
        sum += e;
        count += 1;
    }

    return static_cast<double>(sum) / count;
}

int main() {
    size_t N;
    std::cin >> N;

    std::vector<int> tempDB(N);
    for (size_t i = 0; i < N; ++i) {
        std::cin >> tempDB[i];
    }

    double mean = MeanTemp(tempDB);
    std::vector<size_t> positions;

    for (size_t i = 0; i < tempDB.size(); ++i) {
        if (tempDB[i] > mean)
            positions.push_back(i);
    }

    std::cout << positions.size() << std::endl;
    for (const auto &e: positions) {
        std::cout << e << " ";
    }

    return 0;
}
