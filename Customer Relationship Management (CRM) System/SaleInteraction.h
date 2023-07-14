#ifndef CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_SALEINTERACTION_H
#define CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_SALEINTERACTION_H
#include "Interaction.h"

class SaleInteraction : public Interaction {
private:
    double amount;
    int warrantyPeriod;
public:
    SaleInteraction(const std::string& user, double amount, int warrantyPeriod)
            : Interaction("Sale", user), amount(amount), warrantyPeriod(warrantyPeriod) {}

    double getAmount() const {
        return amount;
    }

    int getWarrantyPeriod() const {
        return warrantyPeriod;
    }
};

#endif //CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_SALEINTERACTION_H
