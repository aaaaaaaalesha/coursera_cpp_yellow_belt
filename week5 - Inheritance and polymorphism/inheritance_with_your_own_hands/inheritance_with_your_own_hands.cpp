// Copyright 2020 aaaaaaaalesha

#include <iostream>

using namespace std;

class Animal {
public:
    explicit Animal(string name = "Animal") : Name(std::move(name)) {}

    const string Name;
};


class Dog : public Animal {
public:
    explicit Dog(const string &name) : Animal(name) {}

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};