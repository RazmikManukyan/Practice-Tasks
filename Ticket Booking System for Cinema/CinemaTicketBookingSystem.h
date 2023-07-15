#ifndef TICKET_BOOKING_SYSTEM_FOR_CINEMA_CINEMATICKETBOOKINGSYSTEM_H
#define TICKET_BOOKING_SYSTEM_FOR_CINEMA_CINEMATICKETBOOKINGSYSTEM_H
#include "Movie.h"
#include "User.h"
#include "Ticket.h"

class CinemaTicketBookingSystem {
    std::vector<Movie> movies;
    std::vector<User> users;
    std::vector<std::string> seats;
public:
    void registerMovie(const Movie &movie) {
        movies.push_back(movie);
    }

    void registerUser(const User &user) {
        users.push_back(user);
    }

    void searchMovie(const std::string &title) const {
        std::cout << "Search Results:" << std::endl;
        std::cout << "---------------" << std::endl;
        for (auto &movie: movies) {
            if (movie.getTitle() == title) {
                std::cout << "Title: " << movie.getTitle() << std::endl;
                std::cout << "Duration: " << movie.getDuration() << " minutes" << std::endl;
                std::cout << "Rating: " << movie.getRating() << std::endl;
                std::cout << "---------------" << std::endl;
            }
        }
    }

    void bookTicket(const std::string& movieTitle, const std::string& showtime, const User& user) {
        Movie* selectedMovie = nullptr;
        for (auto& movie : movies) {
            if (movie.getTitle() == movieTitle) {
                selectedMovie = &movie;
                break;
            }
        }

        if (selectedMovie) {
            std::vector<std::string> showtimes = selectedMovie->getShowTimes();
            auto it = std::find(showtimes.begin(), showtimes.end(), showtime);
            if (it != showtimes.end()) {
                if (seats.size() < 100) {  // Assuming a maximum of 100 seats available
                    std::string seatNumber = generateSeatsNumber();
                    seats.push_back(seatNumber);
                    Ticket ticket(selectedMovie, showtime, seatNumber);
                    ticket.printTicket();
                    ticket.saveTicketToTheFile(user.getName() + "_" + movieTitle + "_" + showtime + ".txt");
                } else {
                    std::cout << "Sorry, the showtime is fully booked." << std::endl;
                }
            } else {
                std::cout << "Invalid showtime for the selected movie." << std::endl;
            }
        } else {
            std::cout << "Movie not found." << std::endl;
        }
    }
private:
    std::string generateSeatsNumber() const {
        int seatIndex = seats.size() + 1;
        int row = (seatIndex - 1) / 10 + 1;
        int seat = (seatIndex - 1) % 10 + 1;
        return "Row " + std::to_string(row) + ", Seat" +std::to_string(seat);
    }
};


#endif //TICKET_BOOKING_SYSTEM_FOR_CINEMA_CINEMATICKETBOOKINGSYSTEM_H
