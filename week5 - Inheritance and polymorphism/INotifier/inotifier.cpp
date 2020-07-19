// Copyright 2020 aaaaaaaalesha

#include <iostream>
#include <string>

class INotifier {
public:
    virtual void Notify(const std::string &message) = 0;
};

class SmsNotifier : public INotifier {
private:
    std::string number_;
public:
    explicit SmsNotifier(std::string number) : number_(std::move(number)) {}

    void Notify(const std::string &message) override {
        SendSms(number_, message);
    }
};

class EmailNotifier : public INotifier {
private:
    std::string email_;
public:
    explicit EmailNotifier(std::string email) : email_(std::move(email)) {}

    void Notify(const std::string &message) override {
        SendEmail(email_, message);
    }
};
