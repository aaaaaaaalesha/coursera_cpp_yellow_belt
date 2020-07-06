// Copyright 2020 aaaaaaaalesha

#include <iostream>
#include <vector>
#include <map>
#include <utility>

// Сигнатуры функций.
template<typename T>
T Sqr(T value);

template<typename T>
std::vector<T> Sqr(const std::vector<T> &value);

template<typename K, typename V>
std::map<K, V> Sqr(const std::map<K, V> &value);

// Для пары
template<typename K, typename V>
std::pair<K, V> Sqr(const std::pair<K, V> &value) {
    return {Sqr(value.first), Sqr(value.second)};
}

// Определение функций.
template<typename T>
T Sqr(T value) {
    return value * value;
}

template<typename T>
std::vector<T> Sqr(const std::vector<T> &value) {
    std::vector<T> sqVec;
    sqVec.reserve(value.size());
    for (const auto &item : value) {
        sqVec.push_back(Sqr(item));
    }

    return sqVec;
}

template<typename K, typename V>
std::map<K, V> Sqr(const std::map<K, V> &value) {
    std::map<K, V> sqMap;
    for (const auto &item : value) {
        sqMap[item.first] = Sqr(item.second);
    }

    return sqMap;
}