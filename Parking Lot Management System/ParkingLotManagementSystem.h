#ifndef PARKING_LOT_MANAGEMENT_SYSTEM_PARKINGLOTMANAGEMENTSYSTEM_H
#define PARKING_LOT_MANAGEMENT_SYSTEM_PARKINGLOTMANAGEMENTSYSTEM_H
#include "ParcingSpace.h"
#include "User.h"
#include <vector>

class ParkingLotManagementSystem {
    std::vector<ParkingSpace> parkingSpaces;
    std::vector<User> users;
public:
    void registerParkingSpace(const ParkingSpace &parkingSpace) {
        parkingSpaces.push_back(parkingSpace);
    }

    void registerUser(const User &user) {
        users.push_back(user);
    }

    void reserveParkingSpace(const std::string &spaceNumber, const std::string &userName) {
        ParkingSpace *selectedSpace = nullptr;
        for (auto &parkingSpace: parkingSpaces) {
            if (parkingSpace.getSpaceNumber() == spaceNumber &&
                parkingSpace.getStatus() == ParkingSpaceStatus::Available) {
                selectedSpace = &parkingSpace;
                break;
            }
        }

        if (selectedSpace) {
            selectedSpace->occupy();
            std::cout << "Parking space " << spaceNumber << " reserved for user " << userName << std::endl;
        } else {
            std::cout << "Parking space " << spaceNumber << " not available or already occupied." << std::endl;
        }
    }

    void vacateParkingSpace(const std::string &spaceNumber) {
        ParkingSpace *selectedSpace = nullptr;
        for (auto &parkingSpace: parkingSpaces) {
            if (parkingSpace.getSpaceNumber() == spaceNumber &&
                parkingSpace.getStatus() == ParkingSpaceStatus::Occupied) {
                selectedSpace = &parkingSpace;
                break;
            }
        }

        if (selectedSpace) {
            selectedSpace->vacate();
            std::cout << "Parking space " << spaceNumber << " vacated." << std::endl;
        } else {
            std::cout << "Parking space " << spaceNumber << " is not occupied." << std::endl;
        }
    }

    void calculateParkingFee(const std::string& spaceNumber, double duration) {
        double totalCost = 0.0;
        ParkingSpaceSize vehicleSize = ParkingSpaceSize::Compact;
        for(auto& parkingSpace : parkingSpaces) {
            if(parkingSpace.getSpaceNumber() == spaceNumber) {
                vehicleSize = parkingSpace.getSize();
                break;
            }
        }
        switch(vehicleSize) {
            case ParkingSpaceSize::Compact:
                totalCost = duration * compactRate;
                break;
            case ParkingSpaceSize::Regular:
                totalCost = duration * regularRate;
                break;
            case ParkingSpaceSize::Large:
                totalCost = duration * largeRate;
                break;
        }
        std::cout << "Parking Fee for space " << spaceNumber << ": $" << totalCost << std::endl;
    }

    void generateParkingLotReport(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            int compactCount = 0;
            int regularCount = 0;
            int largeCount = 0;
            double compactProfit = 0.0;
            double regularProfit = 0.0;
            double largeProfit = 0.0;
            int occupiedCount = 0;

            for (const auto& parkingSpace : parkingSpaces) {
                switch (parkingSpace.getSize()) {
                    case ParkingSpaceSize::Compact:
                        compactCount++;
                        if (parkingSpace.getStatus() == ParkingSpaceStatus::Occupied) {
                            occupiedCount++;
                            compactProfit += 5.0;
                        }
                        break;
                    case ParkingSpaceSize::Regular:
                        regularCount++;
                        if (parkingSpace.getStatus() == ParkingSpaceStatus::Occupied) {
                            occupiedCount++;
                            regularProfit += 7.0;
                        }
                        break;
                    case ParkingSpaceSize::Large:
                        largeCount++;
                        if (parkingSpace.getStatus() == ParkingSpaceStatus::Occupied) {
                            occupiedCount++;
                            largeProfit += 10.0;
                        }
                        break;
                }
            }

            file << "Parking Lot Report:" << std::endl;
            file << "------------------" << std::endl;
            file << "Compact Spaces: " << compactCount << std::endl;
            file << "Regular Spaces: " << regularCount << std::endl;
            file << "Large Spaces: " << largeCount << std::endl;
            file << "Occupied Spaces: " << occupiedCount << std::endl;
            file << "Compact Profit: $" << compactProfit << std::endl;
            file << "Regular Profit: $" << regularProfit << std::endl;
            file << "Large Profit: $" << largeProfit << std::endl;

            file.close();
            std::cout << "Parking lot report saved to file: " << filename << std::endl;
        } else {
            std::cout << "Unable to open file: " << filename << std::endl;
        }
    }

};

#endif //PARKING_LOT_MANAGEMENT_SYSTEM_PARKINGLOTMANAGEMENTSYSTEM_H
