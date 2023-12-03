#include "supplier.h"
#include <iomanip>
#include <fstream>
void supplier::display() const {
    // ���������� ������ ������� �� �������� � ��������� ����
    std::cout << std::left << std::setw(20) << "�����" << std::setw(20) << "����� �������� �����"
        << std::setw(20) << "������ �����" << std::endl;
    std::cout << std::left << std::setw(20) << firma << std::setw(20) << raw_material
        << std::setw(20) << payment << std::endl;
    // ����� �������������� ���������� ������ supplier
}

bool supplier::operator==(const date& rhs) const {
    // ���������� ���������� ��������� ==
    return false; // �������� �� ����������� ������ ���������
}

std::istream& operator>>(std::istream& is, supplier& s) {
    is >> s.firma >> s.raw_material >> s.payment;
    return is;
}

std::istream& supplier::operator>>(std::istream& in) {
    // ���������� ����� ������� �� �������� ������
    std::cout << "������� �������� �����: ";
    in >> firma;
    std::cout << "������� ����� �������� �����: ";
    in >> raw_material;
    std::cout << "������� ������ �����: ";
    in >> payment;
    // ���� �������������� ���������� ������ supplier
    return in;
}

void serialize(std::ofstream& outFile) const override {
    // ������� ���������� ��� �������
    char type = '1';
    outFile.write(&type, sizeof(char));

    // ����� ���������� ������ �������
    outFile.write(reinterpret_cast<const char*>(this), sizeof(supplier));
}

void deserialize(std::ifstream& inFile) override {
    // ��������� ������ �������
    inFile.read(reinterpret_cast<char*>(this), sizeof(supplier));
}
