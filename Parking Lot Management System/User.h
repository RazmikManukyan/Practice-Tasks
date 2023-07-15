#ifndef PARKING_LOT_MANAGEMENT_SYSTEM_USER_H
#define PARKING_LOT_MANAGEMENT_SYSTEM_USER_H
#include "ParcingSpace.h"

class User {
    std::string name;
    ParkingSpaceSize vehicleSize;
public:
    User(const std::string &name, ParkingSpaceSize vehicleSize) : name(name), vehicleSize(vehicleSize) {}

    const std::string &getName() const {
        return name;
    }

    ParkingSpaceSize getVehicleSize() const {
        return vehicleSize;
    }

};

#endif //PARKING_LOT_MANAGEMENT_SYSTEM_USER_H
