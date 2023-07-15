#ifndef LOGISTICS_AND_DELIVERY_MANAGEMENT_SYSTEM_USER_H
#define LOGISTICS_AND_DELIVERY_MANAGEMENT_SYSTEM_USER_H
#include <iostream>

class User {
    std::string name;
    std::string contactInfo;
public:
    explicit User(const std::string &name, const std::string& contactInfo) : name(name), contactInfo(contactInfo) {}

    const std::string &getName() const {
        return name;
    }

    const std::string &getContactInfo() const {
        return contactInfo;
    }
};

#endif //LOGISTICS_AND_DELIVERY_MANAGEMENT_SYSTEM_USER_H
