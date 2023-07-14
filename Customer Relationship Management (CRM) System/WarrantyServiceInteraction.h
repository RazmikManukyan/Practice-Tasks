#ifndef CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_WARRANTYSERVICEINTERACTION_H
#define CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_WARRANTYSERVICEINTERACTION_H
#include "SaleInteraction.h"

class WarrantyServiceInteraction : public Interaction {
private:
    SaleInteraction sale;
    double serviceCost;
public:
    WarrantyServiceInteraction(const SaleInteraction& sale, const std::string& user, double serviceCost)
            : Interaction("Warranty Service", user), sale(sale), serviceCost(serviceCost){}

    const SaleInteraction &getSale() const {
        return sale;
    }

    double getServiceCost() const {
        return serviceCost;
    }
};

#endif //CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_WARRANTYSERVICEINTERACTION_H
