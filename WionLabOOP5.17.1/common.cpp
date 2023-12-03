#include "common.h"
std::istream& operator>>(std::istream& is, date& d) {
    is >> d.day >> d.month >> d.year;
    return is;
}