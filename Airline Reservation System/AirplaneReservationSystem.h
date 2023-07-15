#ifndef AIRLINE_RESERVATION_SYSTEM_AIRPLANERESERVATIONSYSTEM_H
#define AIRLINE_RESERVATION_SYSTEM_AIRPLANERESERVATIONSYSTEM_H
#include "Flight.h"
#include "User.h"
#include "Ticket.h"
#include <vector>

class AirplaneReservationSystem{
private:
    std::vector<Flight> flights;
    std::vector<User> users;
public:
    void registerFlight(const Flight& flight) {
        flights.push_back(flight);
    }

    void registerUser(const User& user) {
        users.push_back(user);
    }

    void searchFlight(const std::string& origin, const std::string& destination, const std::string& departureDate) const {
        std::cout << "Search Results: " << std::endl;
        std::cout << "-----------------" << std::endl;
        for(const auto& flight : flights) {
            if(flight.getOrigin() == origin && flight.getDestination() == destination && flight.getDepartureDateTime() == departureDate &&
               flight.getDepartureDateTime().substr(0, 10) == departureDate) {
                std::cout << "Flight Number: " << flight.getFlightNumber() << std::endl;
                std::cout << "Origin: " << flight.getOrigin() << std::endl;
                std::cout << "Destination: " << flight.getDestination() << std::endl;
                std::cout << "Departure Date/Time: " << flight.getDepartureDateTime() << std::endl;
                std::cout << "Available Seats: " << flight.getAvailableSeats() << std::endl;
                std::cout << "---------------" << std::endl;
            }
        }
    }

    void bookFlight(const std::string& flightNumber, const std::string& passengerName, const std::string& passengerContactInfo) {
        Flight* selectedFlight = nullptr;
        for(auto& flight : flights) {
            if(flight.getFlightNumber() == flightNumber && flight.getAvailableSeats() > 0) {
                selectedFlight = &flight;
                break;
            }
        }

        if(selectedFlight) {
            selectedFlight->bookSeats();
            Ticket ticket(flightNumber, selectedFlight->getOrigin(), selectedFlight->getDestination(), selectedFlight->getDepartureDateTime(), passengerName, passengerContactInfo);
            ticket.printTicket();
            ticket.saveTicketToFile(passengerName + "_ticket.txt");
        } else {
            std::cout << "Flight not found or fully booked." << std::endl;
        }
    }
};


#endif //AIRLINE_RESERVATION_SYSTEM_AIRPLANERESERVATIONSYSTEM_H
