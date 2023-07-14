#ifndef CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_INTERACTION_H
#define CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_INTERACTION_H
#include <iostream>

class Interaction {
protected:
    std::string interactionType;
    time_t date;
    std::string user;
public:
    Interaction(const std::string& interactionType, const std::string& user)
            :interactionType(interactionType), user(user){
        date = time(nullptr);
    }
    std::string getInteractionType() const {
        return interactionType;
    }

    std::string getDate() const {
        return std::string(ctime(&date));
    }

    std::string getUser() const {
        return user;
    }
};

#endif //CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_INTERACTION_H
