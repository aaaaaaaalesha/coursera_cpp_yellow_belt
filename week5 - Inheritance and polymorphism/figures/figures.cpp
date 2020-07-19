// Copyright 2020 aaaaaaaalesha

#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual string Name() const = 0;

    virtual double Perimeter() const = 0;

    virtual double Area() const = 0;
};

class Rect : public Figure {
private:
    double width_;
    double length_;
public:
    Rect(double width, double length) : width_(width), length_(length) {}

    string Name() const override { return "RECT"; }

    double Perimeter() const override { return (length_ + width_) * 2; }

    double Area() const override { return length_ * width_; }

};

class Triangle : public Figure {
private:
    double a_;
    double b_;
    double c_;
public:
    Triangle(double a, double b, double c) : a_(a), b_(b), c_(c) {}

    string Name() const override { return "TRIANGLE"; }

    double Perimeter() const override { return a_ + b_ + c_; }

    double Area() const override {
        double half_p = Perimeter() / 2;
        return sqrt(half_p * (half_p - a_) * (half_p - b_) * (half_p - c_));
    }
};

class Circle : public Figure {
private:
    double radius_;
public:
    Circle(double radius) : radius_(radius) {}

    string Name() const override { return "CIRCLE"; }

    double Perimeter() const override { return 2 * 3.14 * radius_; }

    double Area() const override { return 3.14 * radius_ * radius_; }
};

shared_ptr<Figure> CreateFigure(istringstream &is) {
    string figureType;
    is >> figureType;

    if (figureType == "RECT") {
        double width, height;
        is >> width >> height;
        return make_shared<Rect>(width, height);
    } else if (figureType == "TRIANGLE") {
        double a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    } else {
        double r;
        is >> r;
        return make_shared<Circle>(r);
    }
}

int main() {
    vector<shared_ptr<Figure>>
            figures;
    for (string line; getline(cin, line);) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            is >> ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto &current_figure : figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }

    return 0;
}