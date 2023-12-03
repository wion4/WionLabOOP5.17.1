#include "common.h"
#include "supplier.h"
#include "supplier1.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

std::vector<common*> Sup;
std::vector<common*> Sup1;

void addSupplier() {
    std::string firma;
    double raw_material, payment;

    std::cout << "Введите название фирмы: ";
    std::cin >> firma;

    std::cout << "Введите сумму поставки сырья: ";
    std::cin >> raw_material;

    std::cout << "Введите оплату сырья: ";
    std::cin >> payment;

    Sup.push_back(new supplier(firma, raw_material, payment));
}

void addSupplier1() {
    std::string firma;
    double raw_material;
    int day, month, year;

    std::cout << "Введите название фирмы: ";
    std::cin >> firma;

    std::cout << "Введите сумму поставки сырья: ";
    std::cin >> raw_material;

    std::cout << "Введите дату поставки (дд мм гггг): ";
    std::cin >> day >> month >> year;
    date deliv_date(day, month, year);

    Sup1.push_back(new supplier1(firma, raw_material, deliv_date));
}

void printTable(const std::vector<common*>& products) {
    std::cout << std::left << std::setw(20) << "Фирма" << std::setw(20) << "Сумма поставки сырья" << std::setw(20) << "Дата поставки" << std::endl;
    for (const auto& product : products) {
        product->display();
    }
}
std::vector<common*> Rez;
void searchFirma(const std::string& targetFirma) {
    Rez.clear();

    for (const auto& s : Sup) {
        if (s->getFirma() == targetFirma) {
            Rez.push_back(s);
        }
    }

    for (const auto& s : Sup1) {
        if (s->getName() == targetFirma) {
            Rez.push_back(s);
        }
    }

    std::cout << "\nРезультаты поиска фирмы \"" << targetFirma << "\":" << std::endl;
    printTable(Rez);
}

void searchByDate(const date& targetDate) {
    std::vector<common*> RezDate;

    for (const auto& s : Sup1) {
        if (*s == targetDate) {
            RezDate.push_back(s);
        }
    }

    std::cout << "\nРезультаты поиска по дате " << targetDate.getDay() << '.' << targetDate.getMonth() << '.' << targetDate.getYear() << ":" << std::endl;
    printTable(RezDate);
}

void saveData() {
    std::ofstream outFile("dataSup", std::ios::binary);
    if (outFile.is_open()) {
        for (const auto& s : Sup) {
            s->serialize(outFile);
        }
        outFile.close();
    }
    else {
        std::cerr << "Ошибка открытия файла для сохранения данных: dataSup.bin" << std::endl;
    }

    std::ofstream outFile1("dataSup1", std::ios::binary);
    if (outFile1.is_open()) {
        for (const auto& s : Sup1) {
            s->serialize(outFile1);
        }
        outFile1.close();
    }
    else {
        std::cerr << "Ошибка открытия файла для сохранения данных: dataSup1.bin" << std::endl;
    }
}

void loadData() {
    Sup.clear();
    std::ifstream inFile("dataSup", std::ios::binary);
    if (inFile.is_open()) {
        char type;
        inFile.read(&type, sizeof(char));

        while (inFile.good()) {
            common* item = nullptr;
            if (type == '1') {
                item = new supplier;
            }
            else if (type == '2') {
                item = new supplier1;
            }

            if (item) {
                item->deserialize(inFile);
                Sup.push_back(item);
            }

            inFile.read(&type, sizeof(char));
        }

        inFile.close();
    }
    else {
        std::cerr << "Ошибка открытия файла для загрузки данных: dataSup.bin" << std::endl;
    }

    Sup1.clear();
    std::ifstream inFile1("dataSup1", std::ios::binary);
    if (inFile1.is_open()) {
        char type;
        inFile1.read(&type, sizeof(char));

        while (inFile1.good()) {
            common* item = nullptr;
            if (type == '1') {
                item = new supplier;
            }
            else if (type == '2') {
                item = new supplier1;
            }

            if (item) {
                item->deserialize(inFile1);
                Sup1.push_back(item);
            }

            inFile1.read(&type, sizeof(char));
        }

        inFile1.close();
    }
    else {
        std::cerr << "Ошибка открытия файла для загрузки данных: dataSup1.bin" << std::endl;
    }
}

int main() {
    loadData(); // Загрузка данных при первом запуске программы

    int choice;
    do {
        std::cout << "\nВыберите действие:" << std::endl;
        std::cout << "1. Добавить поставщика" << std::endl;
        std::cout << "2. Добавить поставщика (второй вариант)" << std::endl;
        std::cout << "3. Вывести данные в табличном виде" << std::endl;
        std::cout << "4. Поиск фирмы" << std::endl;
        std::cout << "5. Поиск по дате" << std::endl;
        std::cout << "6. Сохранить данные" << std::endl;
        std::cout << "7. Выйти из программы" << std::endl;
        std::cout << "Выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addSupplier();
            break;
        case 2:
            addSupplier1();
            break;
        case 3:
            std::cout << "\nДанные объектов класса supplier:" << std::endl;
            printTable(Sup);
            std::cout << "\nДанные объектов класса supplier1:" << std::endl;
            printTable(Sup1);
            break;
        case 4:
        {
            std::string targetFirma;
            std::cout << "Введите название фирмы для поиска: ";
            std::cin >> targetFirma;
            searchFirma(targetFirma);
        }
        break;
        case 5:
        {
            date targetDate;
            std::cout << "Введите дату для поиска (день месяц год): ";
            std::cin >> targetDate;
            searchByDate(targetDate);
        }
        break;
        case 6:
            saveData();
            std::cout << "Данные сохранены." << std::endl;
            break;
        case 7:
            std::cout << "Выход из программы. Сохранение данных перед выходом." << std::endl;
            saveData();
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте еще раз." << std::endl;
            break;
        }

    } while (choice != 7);

    // Освобождаем память перед выходом из программы
    for (auto& s : Sup) {
        delete s;
    }

    for (auto& s : Sup1) {
        delete s;
    }

    return 0;
}
