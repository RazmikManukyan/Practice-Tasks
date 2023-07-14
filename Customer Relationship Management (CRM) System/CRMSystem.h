#ifndef CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_CRMSYSTEM_H
#define CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_CRMSYSTEM_H
#include "Customer.h"
#include "SaleInteraction.h"
#include "WarrantyServiceInteraction.h"
#include "ComplaintInteraction.h"
#include <vector>
#include <fstream>

class CRMSystem {
private:
    std::vector<Customer> customers;
    std::vector<Interaction*> interactions;
public:
    void registerCustomer(const Customer& customer) {
        customers.push_back(customer);
    }

    void addInteraction(Interaction* interaction) {
        interactions.push_back(interaction);
    }

    void generateReport(const Customer& customer) const {
        std::cout << "Customer Report" << std::endl;
        std::cout << "---------------" << std::endl;
        std::cout << "Customer Name: " << customer.getName() << std::endl;
        std::cout << "Contact Info: " << customer.getContactInfo() << std::endl;

        std::cout << "Iteration history: " << std::endl;
        for(const auto& interaction : interactions) {
            if(interaction->getUser() == customer.getName()) {
                std::cout << "Interaction type: " << interaction->getInteractionType() << std::endl;
                std::cout << "Interaction Date: " << interaction->getDate() << std::endl;
                if(interaction->getInteractionType() == "Sale") {
                    SaleInteraction* sale = static_cast<SaleInteraction*>(interaction);
                    std::cout << "Amount: $" << sale->getAmount() << std::endl;
                    std::cout << "Warranty Period: " << sale->getWarrantyPeriod() << std::endl;
                } else if(interaction->getInteractionType() == "Warranty Service") {
                    WarrantyServiceInteraction* warrantySale = static_cast<WarrantyServiceInteraction*>(interaction);
                    SaleInteraction sale = warrantySale->getSale();
                    std::cout << "Service Cost: $" << warrantySale->getServiceCost() << std::endl;
                    std::cout << "Sale Interaction - Amount: $" << sale.getAmount() << std::endl;
                    std::cout << "Sale Interaction - Warranty Period: " << sale.getWarrantyPeriod() << std::endl;
                } else if(interaction->getInteractionType() == "Complaint") {
                    ComplaintInteraction* complaint = static_cast<ComplaintInteraction*>(interaction);
                    SaleInteraction sale = complaint->getSale();
                    std::cout << "Description: " << complaint->getDescription() << std::endl;
                    std::cout << "Sale Interaction - Amount: $" << sale.getAmount() << std::endl;
                    std::cout << "Sale Interaction - Warranty Period: " << sale.getWarrantyPeriod() << " months" << std::endl;
                }
                std::cout << std::endl;
            }
        }
    }
};

#endif //CUSTOMER_RELATIONSHIP_MANAGEMENT__CRM__SYSTEM_CRMSYSTEM_H
