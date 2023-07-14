#ifndef ELECTRICITY_BILLING_SYSTEM__CUSTOMER_H
#define ELECTRICITY_BILLING_SYSTEM__CUSTOMER_H
#include <iostream>

class Customer {
private:
    std::string name;
    std::string contactInfo;
    std::string meterNumber;
public:
    Customer(const std::string &name, const std::string &contactInfo, const std::string &meterNumber)
            : name(name), contactInfo(contactInfo),meterNumber(meterNumber) {}

    const std::string &getName() const {
        return name;
    }

    const std::string &getContactInfo() const {
        return contactInfo;
    }

    const std::string &getMeterNumber() const {
        return meterNumber;
    }
};


#endif //ELECTRICITY_BILLING_SYSTEM__CUSTOMER_H
