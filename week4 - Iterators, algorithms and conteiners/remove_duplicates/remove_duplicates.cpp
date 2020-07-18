// Copyright 2020 aaaaaaaalesha

#include <algorithm>
#include <string>
#include <vector>

template<typename T>
void RemoveDuplicates(std::vector<T> &elements) {
    std::sort(elements.begin(), elements.end());
    elements.erase(
            std::unique(elements.begin(), elements.end()),
            elements.end());
}