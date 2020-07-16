// Copyright 2020 aaaaaaaalesha

#include <stdexcept>
#include <iostream>
#include "phone_number.h"

PhoneNumber::PhoneNumber(const string &international_number) {
    if (international_number.length() < 3 ||
        international_number.front() != '+')
        throw invalid_argument("Wrong format");

    size_t first_def_pos = international_number.find('-');
    if (first_def_pos != string::npos) {
        country_code_ = international_number.substr(1, first_def_pos - 1);
    } else {
        throw invalid_argument("Wrong format");
    }

    if (country_code_.empty()) throw invalid_argument("Wrong format");

    size_t second = string::npos;
    if (first_def_pos + 1 < international_number.size()) {
        size_t second_def_pos = international_number.find('-',
                                                          first_def_pos + 1);

        if (second_def_pos != string::npos) {
            city_code_ = international_number.substr(first_def_pos + 1,
                                                     second_def_pos -
                                                     first_def_pos - 1);
            second = second_def_pos;
        } else {
            throw invalid_argument("Wrong format");
        }
    } else {
        throw invalid_argument("Wrong format");
    }

    if (second + 1 < international_number.size()) {
        local_number_ = international_number.substr(second + 1,
                                                    international_number.size() -
                                                    1);
    } else {
        throw invalid_argument("Wrong format");
    }
}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}
