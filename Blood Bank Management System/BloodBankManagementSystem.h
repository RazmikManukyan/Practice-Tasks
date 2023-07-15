#ifndef BLOOD_BANK_MANAGEMENT_SYSTEM_BLOODBANKMANAGEMENTSYSTEM_H
#define BLOOD_BANK_MANAGEMENT_SYSTEM_BLOODBANKMANAGEMENTSYSTEM_H
#include "Donor.h"
#include "BloodOperation.h"
#include <vector>
#include <fstream>

class BloodBankManagementSystem{
    std::vector<Donor> donors;
    std::vector<BloodOperation> bloodOperations;
public:
    void registerDonor(const Donor& donor) {
        donors.push_back(donor);
    }

    void donateBlood(const std::string& bloodType, int count ) {
        BloodOperation operation{bloodType, count, std::time(nullptr)};
        bloodOperations.push_back(operation);
        std::cout << "Blood operation recorded successfully." << std::endl;
    }

    void utilizeBlood(const std::string& bloodType, int count) {
        BloodOperation operation{bloodType, -count, std::time(nullptr)};
        bloodOperations.push_back(operation);
        std::cout << "Blood utilization recorded successfully." << std::endl;
    }

    void searchBlood(const std::string& bloodType) {
        std::cout << "Search Results: " << bloodType << std::endl;
        std::cout << "-----------------------" << std::endl;

        bool found = false;
        for(const auto& operation : bloodOperations) {
            if(operation.bloodType == bloodType) {
                std::cout << "Blood Type: " << operation.bloodType << std::endl;
                std::cout << "Count: " << operation.count << std::endl;
                std::cout << "Date: " << std::asctime(std::localtime(&operation.date));
                std::cout << "------------------------" << std::endl;
                found = true;
            }
        }
        if(!found) {
            std::cout << "No blood available for the specified type." << std::endl;
        }
    }

    void generateInventoryReport() const {
        std::cout << "Blood Inventory Report" << std::endl;
        std::cout << "-------------------------" << std::endl;

        std::vector<std::string> bloodTypes = {"A+", "A-" ,"B+", "B-", "AB+", "AB_", "O+", "O-"};
        for(const auto& bloodType : bloodTypes) {
            int totalUnits = 0;
            for(const auto& operation : bloodOperations) {
                if(operation.bloodType == bloodType) {
                    totalUnits += operation.count;
                }
            }
            std::cout << "Blood type: " << bloodType << std::endl;
            std::cout << "Total Units: " << totalUnits << std::endl;
            std::cout << "--------------------------" << std::endl;
        }
    }

    void generateMonthlyReport(int month, int year) const {
        std::string filename = "monthly_report_" + std::to_string(month) + "_" + std::to_string(year) + ".txt";
        std::ofstream file(filename);
        if(file.is_open()) {
            file << "Monthly Report: " << month << "/" << year << std::endl;
            file << "----------------------------------" << std::endl;

            for(const auto& operation : bloodOperations) {
                std::tm* tm = std::localtime((&operation.date));
                if(tm->tm_mon + 1 == month && tm->tm_year + 1900 == year) {
                    std::string type = operation.count > 0 ? "Donation" : "Utilization";
                    file << "Blood type: " << operation.bloodType << std::endl;
                    file << "Count: " << std::abs(operation.count) << std::endl;
                    file << "Date: " << std::asctime(std::localtime(&operation.date)) << std::endl;
                    file << "Type: " << type << std::endl;
                    file << "------------------------------------" << std::endl;
                }
            }
            file.close();
            std::cout << "Monthly report saved to file: " << filename << std::endl;
        } else {
            std::cout << "Unable to open the file: " << filename << std::endl;
        }
    }
};


#endif //BLOOD_BANK_MANAGEMENT_SYSTEM_BLOODBANKMANAGEMENTSYSTEM_H
