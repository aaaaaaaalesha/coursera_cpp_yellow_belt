// Copyright 2020 aaaaaaaalesha

#include <iostream>
#include <map>
#include <stdexcept>

template<typename Key, typename Value>
Value &GetRefStrict(std::map<Key, Value> &coll, Key key) {
    if (coll.find(key) == coll.end())
        throw std::runtime_error("This key does not exists in collection.");
    else
        return coll.at(key);

}