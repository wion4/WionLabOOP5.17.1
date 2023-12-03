#pragma once
#include <iostream>
#include <string>
#include <fstream>
class date {
private:
    int day;
    int month;
    int year;

public:
    date() = default;
    date(int day, int month, int year) : day(day), month(month), year(year) {}

    // Добавленные методы-геттеры
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Добавьте необходимые методы для работы с датой, если требуется
    bool operator==(const date& rhs) const;
    friend std::istream& operator>>(std::istream& is, date& d);
};

class common {
public:
    virtual void searchToDate(const date& targetDate) = 0;
    virtual void display() const = 0;
    virtual ~common() = default;

    virtual void serialize(std::ofstream& outFile) const = 0;
    virtual void deserialize(std::ifstream& inFile) = 0;
    virtual std::string getName() const = 0;
    virtual bool operator==(const date& rhs) const = 0;
    virtual std::istream& operator>>(std::istream& in) = 0;
    virtual std::string getFirma() const = 0;

    // Добавленный геттер для производных классов

};

