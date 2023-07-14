#ifndef CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_COMPLAINTINTERACTION_H
#define CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_COMPLAINTINTERACTION_H
#include "SaleInteraction.h"

class ComplaintInteraction : public Interaction {
private:
    SaleInteraction sale;
    std::string description;
public:
    ComplaintInteraction(const SaleInteraction& sale, const std::string& user, const std::string& description)
            : Interaction("Compliant", user), sale(sale), description(description){}

    const SaleInteraction &getSale() const {
        return sale;
    }

    const std::string &getDescription() const {
        return description;
    }
};

#endif //CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_COMPLAINTINTERACTION_H
