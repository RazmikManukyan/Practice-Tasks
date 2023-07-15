#ifndef TAXI_BOOKING_SYSTEM_RIDE_H
#define TAXI_BOOKING_SYSTEM_RIDE_H
#include "User.h"
#include "Taxi.h"
#include <fstream>


class Ride {
    const Taxi& taxi;
    const User& user;
    double distance;
    std::string startTime;
    std::string endTime;
    double fare;
public:
    Ride(const Taxi &taxi, const User &user, double distance, const std::string &startTime, const std::string &endTime)
            : taxi(taxi), user(user), distance(distance), startTime(startTime), endTime(endTime), fare(0.0) {}

    const Taxi &getTaxi() const {
        return taxi;
    }

    const User &getUser() const {
        return user;
    }

    double getDistance() const {
        return distance;
    }

    const std::string &getStartTime() const {
        return startTime;
    }

    const std::string &getEndTime() const {
        return endTime;
    }

    double getFare() const {
        return fare;
    }

    void calculateFare() {
        double fareMultiplayer = 1.0;
        if(taxi.getTaxiClass() == "comfort") {
            fareMultiplayer = 1.8;
        } else if(taxi.getTaxiClass() == "business") {
            fareMultiplayer = 3.0;
        }
        fare = fareMultiplayer * distance;
    }

    void printRecipe() const {
        std::cout << "Ride recipe: " << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "Taxi number: " << taxi.getTaxiNumber() << std::endl;
        std::cout << "Driver name: " << taxi.getDriverName() << std::endl;
        std::cout << "User name: " << user.getName() << std::endl;
        std::cout << "User contact info: " << user.getContactInfo() << std::endl;
        std::cout << "Distance traveled: " << distance << " km" << std::endl;
        std::cout << "Start Time: " << startTime << std::endl;
        std::cout << "End Time: " << endTime << std::endl;
        std::cout << "Fare: $" << fare << std::endl;
    }

    void saveRecipeToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if(file.is_open()) {
            file << "Ride recipe: " << std::endl;
            file << "---------------------" << std::endl;
            file << "Taxi number: " << taxi.getTaxiNumber() << std::endl;
            file << "Driver name: " << taxi.getDriverName() << std::endl;
            file << "User name: " << user.getName() << std::endl;
            file << "User contact info: " << user.getContactInfo() << std::endl;
            file << "Distance traveled: " << distance << " km" << std::endl;
            file << "Start Time: " << startTime << std::endl;
            file << "End Time: " << endTime << std::endl;
            file << "Fare: $" << fare << std::endl;
            file.close();
            std::cout << "Recipe saved to file: " << filename << std::endl;
        } else {
            std::cout << "Unable to open file: " << filename << std::endl;
        }
    }
};


#endif //TAXI_BOOKING_SYSTEM_RIDE_H
