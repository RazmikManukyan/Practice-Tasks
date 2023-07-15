#ifndef BLOOD_BANK_MANAGEMENT_SYSTEM_DONOR_H
#define BLOOD_BANK_MANAGEMENT_SYSTEM_DONOR_H
#include <iostream>

class Donor{
    std::string name;
    std::string contactInfo;
    std::string bloodType;
public:
    Donor(const std::string &name, const std::string &contactInfo, const std::string &bloodType)
            : name(name),contactInfo(contactInfo),bloodType(bloodType) {}

    const std::string &getName() const {
        return name;
    }

    const std::string &getContactInfo() const {
        return contactInfo;
    }

    const std::string &getBloodType() const {
        return bloodType;
    }
};

#endif//BLOOD_BANK_MANAGEMENT_SYSTEM_DONOR_H
