#include "supplier1.h"
#include <iomanip>

void supplier1::display() const {
    // Реализация вывода объекта на терминал в табличном виде
    std::cout << std::left << std::setw(20) << "Фирма" << std::setw(20) << "Сумма поставки сырья"
        << std::setw(20) << "Дата поставки" << std::endl;
    std::cout << std::left << std::setw(20) << firma << std::setw(20) << raw_material
        << std::setw(20) << deliv_date.getDay() << '.' << deliv_date.getMonth() << '.'
        << deliv_date.getYear() << std::endl;
    // Вывод дополнительной информации класса supplier1
}

bool supplier1::operator==(const date& rhs) const {
    // Реализация перегрузки оператора ==
    return deliv_date == rhs;
}

std::istream& operator>>(std::istream& is, supplier1& s) {
    is >> s.firma >> s.raw_material >> s.deliv_date;
    return is;
}

std::istream& supplier1::operator>>(std::istream& in) {
    // Реализация ввода объекта из входного потока
    std::cout << "Введите название фирмы: ";
    in >> firma;
    std::cout << "Введите сумму поставки сырья: ";
    in >> raw_material;
    std::cout << "Введите дату поставки (день месяц год через пробел): ";
    in >> deliv_date;
    // Ввод дополнительной информации класса supplier1
    return in;
}
