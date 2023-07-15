#ifndef BLOOD_BANK_MANAGEMENT_SYSTEM_BLOODOPERATION_H
#define BLOOD_BANK_MANAGEMENT_SYSTEM_BLOODOPERATION_H
#include <iostream>

struct BloodOperation{
    std::string bloodType;
    int count;
    std::time_t date;
};

#endif //BLOOD_BANK_MANAGEMENT_SYSTEM_BLOODOPERATION_H
