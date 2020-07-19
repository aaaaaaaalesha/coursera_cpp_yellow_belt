// Copyright 2020 aaaaaaaalesha

#include <utility>
#include <string>

using namespace std;

template<typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin, RandomIt range_end,
        char prefix) {

    return std::make_pair(
            lower_bound(range_begin, range_end, string(1, prefix)),
            lower_bound(range_begin, range_end,
                        string(1, static_cast<char>(prefix + 1))));
}