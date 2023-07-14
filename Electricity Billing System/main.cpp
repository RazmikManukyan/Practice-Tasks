#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include "ElectricityBillingSystem.h"

int main() {
    ElectricityBillingSystem billingSystem(0.15);

    Customer customer1("Joe", "joe@example.com", "12315");
    Customer customer2("Ann", "ann@example.com" , "4124");

    billingSystem.generateBill(customer1, 100);
    billingSystem.generateBill(customer2, 200);

    return 0;
}
