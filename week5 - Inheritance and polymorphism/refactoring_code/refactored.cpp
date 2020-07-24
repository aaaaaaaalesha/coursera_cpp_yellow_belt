// Copyright 2020  <github.com/aaaaaaaalesha>

#include <iostream>
#include <string>
#include <vector>
#include <memory>

/// Teacher, Student, и Policeman являются, по сути, людьми.
/// Создадим класс Human и унаследуемся от него.

class Human {
private:
    std::string name_;
    std::string profession_;
public:
    Human(const std::string &name, const std::string &profession)
            : name_(name), profession_(profession) {}

    std::string GetName() const { return name_; }

    std::string GetProfession() const { return profession_; }


    virtual void Walk(const std::string &destination) const = 0;
};

// Класс студента теперь имеет единственное приватное поле и переопределённый
// метод Walk.
class Student : public Human {
private:
    std::string favoriteSong_;
public:
    Student(const std::string &name, const std::string &favouriteSong)
            : Human(name, "Student"), favoriteSong_(favouriteSong) {}


    // Переопределённый метод Walk для класса Student.
    void Walk(const std::string &destination) const override {
        std::cout << GetProfession() << ": " << GetName() << " walks to: "
                  << destination
                  << std::endl;
        SingSong();
    }

    // Методы Learn() и SingSong() - уникальны, есть только у студента.
    void Learn() const {
        std::cout << GetProfession() << ": " << GetName() << " learns"
                  << std::endl;
    }

    void SingSong() const {
        std::cout << GetProfession() << ": " << GetName() << " sings a song: "
                  << favoriteSong_ << std::endl;
    }
};

// Класс учителя теперь имеет единственное приватное поле и переопределённый
// метод Walk.
class Teacher : public Human {
private:
    std::string subject_;
public:
    Teacher(const std::string &name, const std::string &subject)
            : Human(name, "Teacher"), subject_(subject) {}

    // Переопределённый метод Walk для класса Teacher.
    void Walk(const std::string &destination) const override {
        std::cout << GetProfession() << ": " << GetName() << " walks to: "
                  << destination
                  << std::endl;
    }

    // Метод Teach() - уникальный метод, который есть только у учителя.
    void Teach() const {
        std::cout << GetProfession() << ": " << GetName() << " teaches: "
                  << subject_
                  << std::endl;
    }
};

// В классе полицейского теперь нет дублирования метода Check(...);
// метод Walk также переопределён для него.
class Policeman : public Human {
public:
    explicit Policeman(const std::string &name) : Human(name, "Policeman") {}

    void Check(const Human &h) const {
        std::string prof = h.GetProfession();

        std::cout << GetProfession() << ": " << GetName()
                  << " checks " << h.GetProfession() << ". "
                  << h.GetProfession() << "'s name is: "
                  << h.GetName() << std::endl;
    }

    void Walk(const std::string &destination) const override {
        std::cout << GetProfession() << ": " << GetName() << " walks to: "
                  << destination
                  << std::endl;
    }
};

// Используя умный указатель std::shared_ptr<Human> избавились от дублирования функции VisitPlaces(...).
void
VisitPlaces(const std::shared_ptr<Human> &t,
            const std::vector<std::string> &places) {
    for (const auto &p : places) { t->Walk(p); }
}

// Вывод в функции main() не поменялся, его можно посмотреть в комментарии после неё.
int main() {
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(std::make_shared<Teacher>("Jim", "Math"), {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(std::make_shared<Student>("Ann", "We will rock you"),
                {"Moscow", "London"});

    return 0;
}

/* Output:

Teacher: Jim walks to: Moscow
Teacher: Jim walks to: London
Policeman: Bob checks Student. Student's name is: Ann
Student: Ann walks to: Moscow
Student: Ann sings a song: We will rock you
Student: Ann walks to: London
Student: Ann sings a song: We will rock you

Process finished with exit code 0
*/