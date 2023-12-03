#pragma once
#include "common.h"
class supplier : public common
{
private:
    std::string firma;
    double raw_material;
    double payment;

public:
    supplier() = default;
    supplier(const std::string& firma, double raw_material, double payment)
        : firma(firma), raw_material(raw_material), payment(payment) {}

    void searchToDate(const date& targetDate) override;
    void display() const override;

    bool operator==(const date& rhs) const;
    std::istream& operator>>(std::istream& in);
    friend std::istream& operator>>(std::istream& is, supplier& s);
    std::string getFirma() const override {return firma;}
    double getRawMaterial() const { return raw_material; }
    double getPayment() const { return payment; }
};

