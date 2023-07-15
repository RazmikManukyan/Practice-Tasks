#include "AirplaneReservationSystem.h"

int main() {
    AirplaneReservationSystem system;

    Flight flight1("FL001" , "City A", "City B", "2023-07-01", 100);
    Flight flight2("Fl002", "City B", "City C", "2023-07-02", 75);
    system.registerFlight(flight1);
    system.registerFlight(flight2);

    User user1("Joe", "joe@example.com");
    User user2("Ann", "ann@example.com");
    system.registerUser(user1);
    system.registerUser(user2);

    system.searchFlight("City A", "City B", "2023-07-01");
    system.searchFlight("City B", "City C", "2023-07-02");

    system.bookFlight("FL001", "Joe", "joe@example.com");
    system.bookFlight("FL002", "Ann", "ann@example.com");

    return 0;
}
