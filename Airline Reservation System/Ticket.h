#ifndef AIRLINE_RESERVATION_SYSTEM_TICKET_H
#define AIRLINE_RESERVATION_SYSTEM_TICKET_H
#include <iostream>
#include <fstream>

class Ticket {
private:
    std::string flightNumber;
    std::string origin;
    std::string destination;
    std::string departureDateTime;
    std::string passengerName;
    std::string passengerContactInfo;
private:
public:
    Ticket(const std::string &flightNumber, const std::string &origin, const std::string &destination,
           const std::string &departureDateTime, const std::string &passengerName,
           const std::string &passengerContactInfo)
            : flightNumber(flightNumber), origin(origin), destination(destination),
              departureDateTime(departureDateTime),
              passengerName(passengerName), passengerContactInfo(passengerContactInfo) {}

    void printTicket() const {
        std::cout << "Ticket detail: " << std::endl;
        std::cout << "----------------" << std::endl;
        std::cout << "Flight number: " << flightNumber << std::endl;
        std::cout << "Origin: " << origin << std::endl;
        std::cout << "Destination: " << destination << std::endl;
        std::cout << "Departure Date/Time" << departureDateTime << std::endl;
        std::cout << "Passenger name: " << passengerName << std::endl;
        std::cout << "Passenger Contact Info: " << passengerContactInfo << std::endl;
    }

    void saveTicketToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if(file.is_open()) {
            file << "Ticket detail: " << std::endl;
            file << "----------------" << std::endl;
            file << "Flight number: " << flightNumber << std::endl;
            file << "Origin: " << origin << std::endl;
            file << "Destination: " << destination << std::endl;
            file << "Departure Date/Time" << departureDateTime << std::endl;
            file << "Passenger name: " << passengerName << std::endl;
            file << "Passenger Contact Info: " << passengerContactInfo << std::endl;
            file.close();
            std::cout << "File Save to File: " << filename << std::endl;
        } else {
            std::cout << "Unable to Open the File: " << filename << std::endl;
        }
    }
};

#endif //AIRLINE_RESERVATION_SYSTEM// _TICKET_H
