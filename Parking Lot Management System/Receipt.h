#ifndef PARKING_LOT_MANAGEMENT_SYSTEM_RECEIPT_H
#define PARKING_LOT_MANAGEMENT_SYSTEM_RECEIPT_H
#include "ParcingSpace.h"
#include <iostream>
#include <fstream>

class Receipt {
    std::string spaceNumber;
    ParkingSpaceSize vehicleSize;
    double duration;
    double totalCost;
public:
    Receipt(const std::string &spaceNumber, ParkingSpaceSize vehicleSize, double duration, double totalCost)
            : spaceNumber(spaceNumber), vehicleSize(vehicleSize), duration(duration), totalCost(totalCost) {}

    void printReceipt() const {
        std::cout << "Receipt Details:" << std::endl;
        std::cout << "---------------" << std::endl;
        std::cout << "Space Number: " << spaceNumber << std::endl;
        std::cout << "Vehicle Size: " << getVehicleSizeString() << std::endl;
        std::cout << "Duration (hours): " << duration << std::endl;
        std::cout << "Total Cost: $" << totalCost << std::endl;
    }

    std::string getVehicleSizeString() const {
        switch (vehicleSize) {
            case ParkingSpaceSize::Compact:
                return "Compact";
            case ParkingSpaceSize::Regular:
                return "Regular";
            case ParkingSpaceSize::Large:
                return "Large";
            default:
                return "Unknown";
        }
    }

    void saveReceiptToFile(const std::string &filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << "Receipt Details:" << std::endl;
            file << "---------------" << std::endl;
            file << "Space Number: " << spaceNumber << std::endl;
            file << "Vehicle Size: " << getVehicleSizeString() << std::endl;
            file << "Duration (hours): " << duration << std::endl;
            file << "Total Cost: $" << totalCost << std::endl;
            file.close();
            std::cout << "Receipt saved to file: " << filename << std::endl;
        } else {
            std::cout << "Unable to open file: " << filename << std::endl;
        }
    }
};


#endif //PARKING_LOT_MANAGEMENT_SYSTEM_RECEIPT_H
