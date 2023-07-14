#ifndef FOOD_ORDER_MANAGEMENT_SYSTEM_CUSTOMER_H
#define FOOD_ORDER_MANAGEMENT_SYSTEM_CUSTOMER_H
#include <iostream>

class Customer {
private:
    std::string name;
    std::string contactInfo;
    std::string preferredPaymentMethod;
public:
    Customer(const std::string &name, const std::string &contactInfo, const std::string &preferredPaymentMethod) : name(
            name), contactInfo(contactInfo), preferredPaymentMethod(preferredPaymentMethod) {}

    const std::string &getName() const {
        return name;
    }

    const std::string &getContactInfo() const {
        return contactInfo;
    }

    const std::string &getPreferredPaymentMethod() const {
        return preferredPaymentMethod;
    }
};

#endif //FOOD_ORDER_MANAGEMENT_SYSTEM_CUSTOMER_H
