#include "supplier.h"
#include <iomanip>
#include <fstream>
void supplier::display() const {
    // Реализация вывода объекта на терминал в табличном виде
    std::cout << std::left << std::setw(20) << "Фирма" << std::setw(20) << "Сумма поставки сырья"
        << std::setw(20) << "Оплата сырья" << std::endl;
    std::cout << std::left << std::setw(20) << firma << std::setw(20) << raw_material
        << std::setw(20) << payment << std::endl;
    // Вывод дополнительной информации класса supplier
}

bool supplier::operator==(const date& rhs) const {
    // Реализация перегрузки оператора ==
    return false; // Замените на необходимую логику сравнения
}

std::istream& operator>>(std::istream& is, supplier& s) {
    is >> s.firma >> s.raw_material >> s.payment;
    return is;
}

std::istream& supplier::operator>>(std::istream& in) {
    // Реализация ввода объекта из входного потока
    std::cout << "Введите название фирмы: ";
    in >> firma;
    std::cout << "Введите сумму поставки сырья: ";
    in >> raw_material;
    std::cout << "Введите оплату сырья: ";
    in >> payment;
    // Ввод дополнительной информации класса supplier
    return in;
}

void serialize(std::ofstream& outFile) const override {
    // Сначала записываем тип объекта
    char type = '1';
    outFile.write(&type, sizeof(char));

    // Затем записываем данные объекта
    outFile.write(reinterpret_cast<const char*>(this), sizeof(supplier));
}

void deserialize(std::ifstream& inFile) override {
    // Считываем данные объекта
    inFile.read(reinterpret_cast<char*>(this), sizeof(supplier));
}
