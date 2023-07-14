#ifndef ELECTRICITY_BILLING_SYSTEM__ELECTRICITYBILL_H
#define ELECTRICITY_BILLING_SYSTEM__ELECTRICITYBILL_H
#include "Customer.h"

class ElectricityBill {
private:
    Customer customer;
    std::string billDate;
    double consumption;
    double ratePerUnit;
public:
    ElectricityBill(const Customer& customer, double consumption, double ratePerUnit)
            : customer(customer), consumption(consumption), ratePerUnit(ratePerUnit){
        time_t now = time(nullptr);
        billDate = ctime(&now);

    }

    const Customer &getCustomer() const {
        return customer;
    }

    double getConsumption() const {
        return consumption;
    }

    double getRatePerUnit() const {
        return ratePerUnit;
    }

    double getTotalAmount() const {
        return consumption * ratePerUnit;
    }

    std::string getBillDate() const {
        return billDate;
    }
};


#endif //ELECTRICITY_BILLING_SYSTEM__ELECTRICITYBILL_H
