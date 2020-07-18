// Copyright 2020 aaaaaaaalesha

#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

// The number of permutations of n objects is equal to n!
size_t NumberOfPermutations(size_t n) {
    if (n == 1) return 1;

    return NumberOfPermutations(n - 1) * n;
}

void PrintPermtations(size_t n) {
    std::vector<int> permutation(n);

    std::iota(permutation.begin(), permutation.end(), 1);

    reverse(permutation.begin(), permutation.end());

    do {
        for (int num : permutation) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } while (prev_permutation(permutation.begin(), permutation.end()));

}

int main() {
    size_t n;
    std::cin >> n;

    PrintPermtations(n);

    return 0;
}