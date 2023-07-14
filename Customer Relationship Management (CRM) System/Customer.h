#ifndef CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_CUSTOMER_H
#define CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_CUSTOMER_H
#include <iostream>

class Customer {
private:
    std::string name;
    std::string contactInfo;
public:
    Customer(const std::string &name, const std::string &contactInfo)
            : name(name), contactInfo(contactInfo) {}

    const std::string &getName() const {
        return name;
    }

    const std::string &getContactInfo() const {
        return contactInfo;
    }
};

#endif //CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_CUSTOMER_H
