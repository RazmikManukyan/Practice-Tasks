#ifndef TICKET_BOOKING_SYSTEM_FOR_CINEMA_USER_H
#define TICKET_BOOKING_SYSTEM_FOR_CINEMA_USER_H
#include <iostream>

class User {
    std::string name;
    std::string contactInfo;
public:
    User(const std::string &name, const std::string &contactInfo)
            : name(name), contactInfo(contactInfo) {}

    const std::string &getName() const {
        return name;
    }

    const std::string &getContactInfo() const {
        return contactInfo;
    }
};


#endif //TICKET_BOOKING_SYSTEM_FOR_CINEMA_USER_H
