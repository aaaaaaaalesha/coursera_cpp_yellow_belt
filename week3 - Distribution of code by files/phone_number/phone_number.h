#pragma once

#include <string>

using namespace std;

class PhoneNumber {
private:
    string country_code_;
    string city_code_;
    string local_number_;

public:
    /* Принимает строку в формате +XXX-YYY-ZZZZZZ
       XXX - это код страны.
       YYY - код города
       ZZZZZZ - местный номер.
       Код страны, код города и местный номер не должны быть пустыми.
       Если строка не соответствует этому формату, нужно выбросить исключение invalid_argument. Проверять, что номер содержит только цифры, не нужно.

       Примеры:
       * +7-495-111-22-33
       * +7-495-1112233
       * +323-22-460002
       * +1-2-coursera-cpp
       * 1-2-333 - некорректный номер - не начинается на '+'
       * +7-1233 - некорректный номер - есть только код страны и города
    */
    explicit PhoneNumber(const string &international_number);

    string GetCountryCode() const;
    string GetCityCode() const;
    string GetLocalNumber() const;
    string GetInternationalNumber() const;
};


