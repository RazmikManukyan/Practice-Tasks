#ifndef TRAVEL_AGENCY_BOOKING_SYSTEM_TRAVELAGENCYBOOKINGSYSTEM_H
#define TRAVEL_AGENCY_BOOKING_SYSTEM_TRAVELAGENCYBOOKINGSYSTEM_H
#include <vector>
#include "User.h"
#include "TravelPackage.h"
#include "Ticket.h"

class TravelAgencyBookingSystem {
    std::vector<TravelPackage> travelPackages;
    std::vector<User> users;
public:
    void registerTravelPackage(const TravelPackage &travelPackage) {
        travelPackages.push_back(travelPackage);
    }

    void registerUser(const User &user) {
        users.push_back(user);
    }

    void searchTravelPackage(double maxPrice, int slotsNeeded) const {
        std::cout << "Search Results:" << std::endl;
        std::cout << "---------------" << std::endl;
        for (auto &travelPackage: travelPackages) {
            if (travelPackage.getPrice() <= maxPrice && travelPackage.getAvailableSlots() >= slotsNeeded) {
                std::cout << "Destination: " << travelPackage.getDestination() << std::endl;
                std::cout << "Price: " << travelPackage.getPrice() << std::endl;
                std::cout << "Available Slots: " << travelPackage.getAvailableSlots() << std::endl;
                std::cout << "---------------" << std::endl;
            }
        }
    }

    void bookTravelPackage(const std::string &destination, const std::string &itinerary,
                           const std::string &passengerName, const std::string &passengerContactInfo) {
        TravelPackage *selectedPackage = nullptr;
        for (auto &travelPackage: travelPackages) {
            if (travelPackage.getDestination() == destination && travelPackage.getAvailableSlots() > 0) {
                selectedPackage = &travelPackage;
                break;
            }
        }
        if (selectedPackage) {
            selectedPackage->bookSlot();
            Ticket ticket(destination, itinerary, passengerName, passengerContactInfo);
            ticket.printTicket();
            ticket.saveTicketToFile(passengerName + " - " + destination + ".txt");
        } else {
            std::cout << "Travel package not found or fully booked." << std::endl;
        }
    }
};

#endif //TRAVEL_AGENCY_BOOKING_SYSTEM_TRAVELAGENCYBOOKINGSYSTEM_H
