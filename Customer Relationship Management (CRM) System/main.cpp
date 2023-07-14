#include "CRMSystem.h"

int main() {
    CRMSystem crmSystem;

    Customer customer1("Joe", "joe@example.com");
    Customer customer2("Ann", "ann@example.com");

    SaleInteraction saleInteraction("Joe", 1000.0, 12);
    WarrantyServiceInteraction warrantyServiceInteraction(saleInteraction, "Joe", 50.0);
    ComplaintInteraction complaintInteraction(saleInteraction, "Ann", "Product not working properly");


    crmSystem.addInteraction(&saleInteraction);
    crmSystem.addInteraction(&warrantyServiceInteraction);
    crmSystem.addInteraction(&complaintInteraction);

    crmSystem.generateReport(customer1);

    return 0;
}
