#ifndef PARKING_LOT_MANAGEMENT_SYSTEM_PARCINGSPACE_H
#define PARKING_LOT_MANAGEMENT_SYSTEM_PARCINGSPACE_H
#include <iostream>

const double compactRate = 5.0;
const double regularRate = 7.0;
const double largeRate = 10.0;

enum class ParkingSpaceSize {
    Compact,
    Regular,
    Large
};

enum class ParkingSpaceStatus {
    Available,
    Occupied
};

class ParkingSpace {
    std::string spaceNumber;
    ParkingSpaceSize size;
    ParkingSpaceStatus status;
public:
    ParkingSpace(const std::string &spaceNumber, ParkingSpaceSize size)
            : spaceNumber(spaceNumber), size(size), status(ParkingSpaceStatus::Available) {}

    const std::string &getSpaceNumber() const {
        return spaceNumber;
    }

    ParkingSpaceSize getSize() const {
        return size;
    }

    ParkingSpaceStatus getStatus() const {
        return status;
    }

    void occupy() {
        status = ParkingSpaceStatus::Occupied;
    }

    void vacate() {
        status = ParkingSpaceStatus::Available;
    }
};


#endif //PARKING_LOT_MANAGEMENT_SYSTEM_PARCINGSPACE_H
