// Copyright 2020 aaaaaaaalesha

#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <limits>

template<class T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &s) {
    os << "{";
    bool first = true;
    for (const auto &x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class K, class V>
std::ostream &operator<<(std::ostream &os, const std::map<K, V> &m) {
    os << "{";
    bool first = true;
    for (const auto &kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T &t, const U &u,
                 const std::string &hint) {
    if (t != u) {
        std::ostringstream os;
        os << "Assertion failed: " << t << " != " << u
           << " hint: " << hint;
        throw std::runtime_error(os.str());
    }
}

inline void Assert(bool b, const std::string &hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template<class TestFunc>
    void RunTest(TestFunc func, const std::string &test_name) {
        try {
            func();
            std::cerr << test_name << " OK" << std::endl;
        } catch (std::runtime_error &e) {
            ++fail_count;
            std::cerr << test_name << " fail: " << e.what() << std::endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            std::cerr << fail_count << " unit tests failed. Terminate" << std::endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

// Пример функции, которую нужно протестировать.
uint32_t Div(uint32_t a, uint32_t b) {
    if (b == 0)
        return std::numeric_limits<uint32_t>::max();

    return a / b;
}

// Пример тестов.
void TestDiv() {
    AssertEqual(Div(10, 2), 5, "Div by even");
    AssertEqual(Div(3, 2), 1, "Div by odd");
}

// Вызов тестов в функции main().
int main() {
    TestRunner tr;
    tr.RunTest(TestDiv, "TestDiv");

    return 0;
}