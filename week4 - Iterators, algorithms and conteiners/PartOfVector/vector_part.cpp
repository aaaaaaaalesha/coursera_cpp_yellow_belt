// Copyright 2020 aaaaaaaalesha

#include <iostream>
#include <vector>
#include <algorithm>


void PrintVectorPart(const std::vector<int> &numbers) {

    auto it = std::find_if(numbers.begin(), numbers.end(), [](int n) { return n < 0; });

    while (it != numbers.begin()) {
        --it;
        std::cout << *it << " ";
    }
}