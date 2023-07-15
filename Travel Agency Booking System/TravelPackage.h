#ifndef TRAVEL_AGENCY_BOOKING_SYSTEM_TRAVELPACKAGE_H
#define TRAVEL_AGENCY_BOOKING_SYSTEM_TRAVELPACKAGE_H
#include <iostream>

class TravelPackage {
private:
    std::string destination;
    double price;
    int availableSlots;
public:
    TravelPackage(const std::string &destination, double price, int availableSlots)
            : destination(destination), price(price), availableSlots(availableSlots) {}

    const std::string &getDestination() const {
        return destination;
    }

    double getPrice() const {
        return price;
    }

    int getAvailableSlots() const {
        return availableSlots;
    }

    void bookSlot() {
        if (availableSlots > 0) {
            availableSlots--;
        }
    }
};

#endif //TRAVEL_AGENCY_BOOKING_SYSTEM_TRAVELPACKAGE_H
