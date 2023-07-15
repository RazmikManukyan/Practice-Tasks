#ifndef AIRLINE_RESERVATION_SYSTEM_FLIGHT_H
#define AIRLINE_RESERVATION_SYSTEM_FLIGHT_H
#include <iostream>

class Flight {
private:
    std::string flightNumber;
    std::string origin;
    std::string destination;
    std::string departureDateTime;
    int availableSeats;
public:
    Flight(const std::string &flightNumber, const std::string &origin, const std::string &destination,
           const std::string &departureDateTime, int availableSeats)
            : flightNumber(flightNumber), origin(origin), destination(destination),
              departureDateTime(departureDateTime), availableSeats(availableSeats) {}

    const std::string &getFlightNumber() const {
        return flightNumber;
    }

    const std::string &getOrigin() const {
        return origin;
    }

    const std::string &getDestination() const {
        return destination;
    }

    const std::string &getDepartureDateTime() const {
        return departureDateTime;
    }

    int getAvailableSeats() const {
        return availableSeats;
    }

    void bookSeats() {
        if (availableSeats > 0) {
            availableSeats--;
        }
    }
};


#endif //AIRLINE_RESERVATION_SYSTEM_FLIGHT_H
