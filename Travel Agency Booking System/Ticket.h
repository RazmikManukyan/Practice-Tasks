#ifndef TRAVEL_AGENCY_BOOKING_SYSTEM_TICKET_H
#define TRAVEL_AGENCY_BOOKING_SYSTEM_TICKET_H
#include <iostream>
#include <fstream>

class Ticket {
    std::string travelPacket;
    std::string itinerary;
    std::string passengerName;
    std::string passengerContactInfo;
public:
    Ticket(const std::string &travelPacket, const std::string &itinerary, const std::string &passengerName,
           const std::string &passengerContactInfo)
            : travelPacket(travelPacket), itinerary(itinerary),
              passengerName(passengerName),
              passengerContactInfo(passengerContactInfo) {}

    void printTicket() const {
        std::cout << "Ticket Details: " << std::endl;
        std::cout << "-----------------------" << std::endl;
        std::cout << "Travel Packet: " << travelPacket << std::endl;
        std::cout << "Itinerary: " << itinerary << std::endl;
        std::cout << "Passenger Name: " << passengerName << std::endl;
        std::cout << "Passenger Contact Info: " << std::endl;
    }

    void saveTicketToFile(const std::string &filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << "Ticket Details: " << std::endl;
            file << "-----------------------" << std::endl;
            file << "Travel Packet: " << travelPacket << std::endl;
            file << "Itinerary: " << itinerary << std::endl;
            file << "Passenger Name: " << passengerName << std::endl;
            file << "Passenger Contact Info: " << std::endl;
            file.close();
            std::cout << "Ticket saved to file: " << filename << std::endl;
        } else {
            std::cout << "Unable to open the file: " << filename << std::endl;
        }
    }
};

#endif //TRAVEL_AGENCY_BOOKING_SYSTEM_TICKET_H
