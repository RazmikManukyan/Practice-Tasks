#include "BloodBankManagementSystem.h"

int main() {
    BloodBankManagementSystem bloodBank;

    Donor donor1("Joe", "joe@example.com" , "A+");
    Donor donor2("Ann", "ann@example.com" , "O-");
    bloodBank.registerDonor(donor1);
    bloodBank.registerDonor(donor2);

    bloodBank.donateBlood("A+", 2);
    bloodBank.donateBlood("O-", 1);
    bloodBank.utilizeBlood("A+", 1);
    bloodBank.utilizeBlood("B-", 2);

    bloodBank.searchBlood("A+");
    bloodBank.searchBlood("AB+");
    bloodBank.searchBlood("B-");

    bloodBank.generateInventoryReport();
    bloodBank.generateMonthlyReport(7, 2023);
}