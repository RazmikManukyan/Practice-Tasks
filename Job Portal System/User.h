#ifndef JOB_PORTAL_SYSTEM_USER_H
#define JOB_PORTAL_SYSTEM_USER_H
#include <iostream>

class User {
    std::string name;
    std::string contactInfo;
    std::string resume;
public:
    User(const std::string &name, const std::string &contactInfo, const std::string &resume)
            : name(name),contactInfo(contactInfo),resume(resume) {}

    const std::string &getName() const {
        return name;
    }

    const std::string &getContactInfo() const {
        return contactInfo;
    }

    const std::string &getResume() const {
        return resume;
    }
};

#endif //JOB_PORTAL_SYSTEM_USER_H
