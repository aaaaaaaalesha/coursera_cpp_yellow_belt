// Copyright 2020 aaaaaaaalesha

#include <algorithm>
#include <set>

using namespace std;

set<int>::const_iterator
FindNearestElement(const set<int> &numbers, int border) {

    const auto lowerIt = numbers.lower_bound(border);

    if (lowerIt == numbers.begin()) return lowerIt;

    if (lowerIt == numbers.end()) return prev(lowerIt);

    if (border - *prev(lowerIt) <= *lowerIt - border) {
        return prev(lowerIt);
    } else {
        return lowerIt;
    }
}
