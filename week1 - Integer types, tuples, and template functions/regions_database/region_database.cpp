// Copyright 2020 aaaaaaaalesha

#include <iostream>
#include <vector>
#include <map>
#include <tuple>

enum class Lang {
    DE, FR, IT
};

struct Region {
    std::string std_name;
    std::string parent_std_name;
    std::map<Lang, std::string> names;
    int64_t population;
};

bool operator<(const Region &lhs, const Region &rhs) {
    return std::tie(lhs.std_name, lhs.parent_std_name, lhs.names,
                    lhs.population) <
           std::tie(rhs.std_name, rhs.parent_std_name, rhs.names,
                    rhs.population);
}

int FindMaxRepetitionCount(const std::vector<Region> &regions) {
    if (regions.empty()) return 0;

    std::map<Region, int> mapOfRepetitions;
    for (const auto &r : regions) ++mapOfRepetitions[r];

    int maxRepetition = 0;
    for (const auto &item : mapOfRepetitions) {
        if (item.second > maxRepetition) {
            maxRepetition = item.second;
        }
    }
    return maxRepetition;
}
