#pragma once
#include "common.h"

class supplier1 : public common {
private:
    std::string firma;
    double raw_material;
    date deliv_date;

public:
    supplier1() = default;
    supplier1(const std::string& firma, double raw_material, const date& deliv_date)
        : firma(firma), raw_material(raw_material), deliv_date(deliv_date) {}

    void display() const override;
    bool operator==(const date& rhs) const override;
    std::istream& operator>>(std::istream& in) override;
    friend std::istream& operator>>(std::istream& is, supplier1& s);
    const std::string getFirma() const { return firma; }
    double getRawMaterial() const { return raw_material; }
    const date& getDelivDate() const { return deliv_date; }

};

