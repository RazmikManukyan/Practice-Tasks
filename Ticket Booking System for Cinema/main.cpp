#include "CinemaTicketBookingSystem.h"

int main() {
    CinemaTicketBookingSystem bookingSystem;

    Movie movie1("The Matrix", 150, "PG-13");
    movie1.addShowTime("2023-07-01 18:00");
    movie1.addShowTime("2023-07-01 20:30");
    bookingSystem.registerMovie(movie1);

    Movie movie2("Inception", 160, "PG-13");
    movie2.addShowTime("2023-07-01 19:30");
    movie2.addShowTime("2023-07-02 14:00");
    bookingSystem.registerMovie(movie2);

    User user1("John Doe", "john@example.com");
    User user2("Jane Smith", "jane@example.com");
    bookingSystem.registerUser(user1);
    bookingSystem.registerUser(user2);

    bookingSystem.searchMovie("Matrix");

    bookingSystem.bookTicket("The Matrix", "2023-07-01 18:00", user1);
    bookingSystem.bookTicket("Inception", "2023-07-02 14:00", user2);

    return 0;
}
