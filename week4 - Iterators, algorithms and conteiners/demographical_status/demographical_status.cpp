// Copyright 2020 aaaaaaaalesha

#include <algorithm>
#include <vector>
#include <iostream>

enum class Gender {
    FEMALE,
    MALE
};

struct Person {
    int age;  // возраст
    Gender gender;  // пол
    bool is_employed;  // имеет ли работу
};

template<typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
    if (range_begin == range_end) {
        return 0;
    }
    std::vector<typename InputIt::value_type> range_copy(range_begin,
                                                         range_end);
    auto middle = begin(range_copy) + range_copy.size() / 2;
    nth_element(
            begin(range_copy), middle, end(range_copy),
            [](const Person &lhs, const Person &rhs) {
                return lhs.age < rhs.age;
            }
    );
    return middle->age;
}

void PrintStats(std::vector<Person> persons) {
    std::cout << "Median age = "
              << ComputeMedianAge(persons.begin(), persons.end()) << std::endl;

    // Сначала женщины, потом мужчины (итератор укажет на первого мужчину).
    auto firstManIt = std::partition(persons.begin(), persons.end(),
                                     [](Person p) {
                                         return p.gender == Gender::FEMALE;
                                     });
    std::cout << "Median age for females = "
              << ComputeMedianAge(persons.begin(), firstManIt) << std::endl;

    std::cout << "Median age for males = "
              << ComputeMedianAge(firstManIt, persons.end()) << std::endl;

    // Теперь сначала идут занятые женщины,
    // потом - безработные, и потом - все мужчины.
    auto firstUnemployedFemaleIt = std::partition(persons.begin(), firstManIt,
                                                  [](Person p) {
                                                      return p.is_employed;
                                                  });

    std::cout << "Median age for employed females = "
              << ComputeMedianAge(persons.begin(), firstUnemployedFemaleIt)
              << std::endl;

    std::cout << "Median age for unemployed females = "
              << ComputeMedianAge(firstUnemployedFemaleIt, firstManIt)
              << std::endl;

    // Ну и аналогично сортируем мужскую половину:
    // сначала трудоустроенные, затем - нет.
    auto firstUnemployedMaleIt = std::partition(firstManIt, persons.end(),
                                                [](Person p) {
                                                    return p.is_employed;
                                                });

    std::cout << "Median age for employed males = "
              << ComputeMedianAge(firstManIt, firstUnemployedMaleIt)
              << std::endl;

    std::cout << "Median age for unemployed males = "
              << ComputeMedianAge(firstUnemployedMaleIt, persons.end())
              << std::endl;

}