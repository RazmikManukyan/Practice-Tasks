#ifndef TAXI_BOOKING_SYSTEM_TAXIBOOKINGSYSTEM_H
#define TAXI_BOOKING_SYSTEM_TAXIBOOKINGSYSTEM_H
#include "Taxi.h"
#include "User.h"
#include "Ride.h"
#include <vector>

class TaxiBookingSystem {
    std::vector<Taxi> taxis;
    std::vector<User> users;
    std::vector<Ride> rides;
public:
    const std::vector<Taxi> &getTaxis() const {
        return taxis;
    }

    const std::vector<User> &getUsers() const {
        return users;
    }

    const std::vector<Ride> &getRides() const {
        return rides;
    }

    void registerTaxi(const Taxi& taxi) {
        taxis.push_back(taxi);
    }

    void registerUser(const User& user) {
        users.push_back(user);
    }

    void bookTaxi(const User& user, double distance, const std::string& starTime, const std::string& endTime) {
        Taxi* availableTaxi = nullptr;
        for(auto& taxi : taxis) {
            if(taxi.getStatus() == "Available") {
                availableTaxi = &taxi;
                break;
            }
        }

        if(availableTaxi){
            availableTaxi->setStatus("Booked");
            Ride ride(*availableTaxi, user, distance, starTime, endTime);
            ride.calculateFare();
            ride.printRecipe();
            rides.push_back(ride);
        } else {
            std::cout << "No available taxi at the moment. " << std::endl;
        }
    }

    void saveRideRecipeToFile(const std::string& filename) const {
        if(rides.empty()) {
            std::cout << "No ride receipts to save. " << std::endl;
            return;
        }

        std::ofstream file(filename);
        if(file.is_open()) {
            for (const auto& ride : rides) {
                file << "Ride Receipt" << std::endl;
                file << "---------------------------" << std::endl;
                file << "Taxi Number: " << ride.getTaxi().getTaxiNumber() << std::endl;
                file << "Driver Name: " << ride.getTaxi().getDriverName() << std::endl;
                file << "User Name: " << ride.getUser().getName() << std::endl;
                file << "User Contact Info: " << ride.getUser().getContactInfo() << std::endl;
                file << "Distance Traveled: " << ride.getDistance() << " km" << std::endl;
                file << "Start Time: " << ride.getStartTime() << std::endl;
                file << "End Time: " << ride.getEndTime() << std::endl;
                file << "Fare: $" << ride.getFare() << std::endl;
                file << "---------------------------" << std::endl;
            }
            file.close();
            std::cout << "Ride receipts saved to file: " << filename << std::endl;
        } else {
            std::cout << "Unable to open file: " << filename << std::endl;
        }
    }
};



#endif //TAXI_BOOKING_SYSTEM_TAXIBOOKINGSYSTEM_H
