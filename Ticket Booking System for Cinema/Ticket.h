#ifndef TICKET_BOOKING_SYSTEM_FOR_CINEMA_TICKET_H
#define TICKET_BOOKING_SYSTEM_FOR_CINEMA_TICKET_H
#include "Movie.h"
#include <fstream>

class Ticket {
    const Movie *movie;
    std::string showTime;
    std::string seatNumber;
public:
    Ticket(const Movie *movie, const std::string &showTime, const std::string &seatNumber)
            : movie(movie), showTime(showTime), seatNumber(seatNumber) {}

    void printTicket() const {
        std::cout << "Ticket Details: " << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "Movie: " << movie->getTitle() << std::endl;
        std::cout << "Show time: " << showTime;
        std::cout << "Seat number: " << seatNumber << std::endl;
        std::cout << "Enjoy the movie!" << std::endl;
    }

    void saveTicketToTheFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << "Ticket Details" << std::endl;
            file << "---------------------------" << std::endl;
            file << "Movie Title: " << movie->getTitle() << std::endl;
            file << "Showtime: " << showTime << std::endl;
            file << "Seat Number: " << seatNumber << std::endl;
            file.close();
            std::cout << "Ticket saved to file: " << filename << std::endl;
        } else {
            std::cout << "Unable to open the file: " << filename << std::endl;
        }
    }
};



#endif //TICKET_BOOKING_SYSTEM_FOR_CINEMA_TICKET_H
