#include "supplier1.h"
#include <iomanip>

void supplier1::display() const {
    // ���������� ������ ������� �� �������� � ��������� ����
    std::cout << std::left << std::setw(20) << "�����" << std::setw(20) << "����� �������� �����"
        << std::setw(20) << "���� ��������" << std::endl;
    std::cout << std::left << std::setw(20) << firma << std::setw(20) << raw_material
        << std::setw(20) << deliv_date.getDay() << '.' << deliv_date.getMonth() << '.'
        << deliv_date.getYear() << std::endl;
    // ����� �������������� ���������� ������ supplier1
}

bool supplier1::operator==(const date& rhs) const {
    // ���������� ���������� ��������� ==
    return deliv_date == rhs;
}

std::istream& operator>>(std::istream& is, supplier1& s) {
    is >> s.firma >> s.raw_material >> s.deliv_date;
    return is;
}

std::istream& supplier1::operator>>(std::istream& in) {
    // ���������� ����� ������� �� �������� ������
    std::cout << "������� �������� �����: ";
    in >> firma;
    std::cout << "������� ����� �������� �����: ";
    in >> raw_material;
    std::cout << "������� ���� �������� (���� ����� ��� ����� ������): ";
    in >> deliv_date;
    // ���� �������������� ���������� ������ supplier1
    return in;
}
