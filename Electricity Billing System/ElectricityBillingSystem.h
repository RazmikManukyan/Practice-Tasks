#ifndef ELECTRICITY_BILLING_SYSTEM__ELECTRICITYBILLINGSYSTEM_H
#define ELECTRICITY_BILLING_SYSTEM__ELECTRICITYBILLINGSYSTEM_H
#include "ElectricityBill.h"

class ElectricityBillingSystem{
private:
    double ratePerUnit;
public:
    ElectricityBillingSystem(double ratePerUnit) : ratePerUnit(ratePerUnit) {}

    void generateBill(const Customer& customer, double consumption) {
        ElectricityBill bill(customer, consumption, ratePerUnit);

        std::cout << "Electricity Bill: " << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "Customer name: " << bill.getCustomer().getName() << std::endl;
        std::cout << "Contact info: " << bill.getCustomer().getContactInfo() << std::endl;
        std::cout << "Meter Number: " << bill.getCustomer().getMeterNumber() << std::endl;
        std::cout << "Bill Date: " << bill.getBillDate() << std::endl;
        std::cout << "Consumption: " << bill.getConsumption() << std::endl;
        std::cout << "Rate per unit: $" << bill.getRatePerUnit() << std::endl;
        std::cout << "Total amount: $" << bill.getTotalAmount() << std::endl;

    }

    void saveBillToFile(const ElectricityBill& bill) {
        std::string filename = bill.getCustomer().getName() + bill.getBillDate() + ".txt";
        std::ofstream file(filename);
        if(file.is_open()) {
            file << "Electricity Bill" << std::endl;
            file << "----------------" << std::endl;
            file << "Customer Name: " << bill.getCustomer().getName() << std::endl;
            file << "Contact Info: " << bill.getCustomer().getContactInfo() << std::endl;
            file << "Meter Number: " << bill.getCustomer().getMeterNumber() << std::endl;
            file << "Bill Date: " << bill.getBillDate();
            file << "Consumption: " << bill.getConsumption() << " units" << std::endl;
            file << "Rate per Unit: $" << bill.getRatePerUnit() << std::endl;
            file << "Total Amount Due: $" << bill.getTotalAmount() << std::endl;
            file.close();
            std::cout << "Bill saved to file: " << filename << std::endl;
        } else {
            std::cout << "Unable to open the file for saving the bill." << std::endl;
        }
    }
};

#endif //ELECTRICITY_BILLING_SYSTEM__ELECTRICITYBILLINGSYSTEM_H
