#include "TravelAgencyBookingSystem.h"

int main() {

    TravelAgencyBookingSystem bookingSystem;
    TravelPackage aPackage1("Paris", 1500.5, 10);
    bookingSystem.registerTravelPackage(aPackage1);
    TravelPackage package2("New York", 2000.0, 5);
    bookingSystem.registerTravelPackage(package2);

    User user1("Joe", "jof@example.com");
    User user2("Ann" , "ann@axample.com");
    bookingSystem.registerUser(user1);
    bookingSystem.registerUser(user2);

    bookingSystem.searchTravelPackage(1800.0, 2);
    bookingSystem.bookTravelPackage("Paris", "Day 1: Eiffel Tower, Day 2: Louvre Museum",
                                    "John Doe", "john@example.com");
    bookingSystem.bookTravelPackage("New York", "Day 1: Statue of Liberty, Day 2: Times Square",
                                    "Jane Smith", "jane@example.com");

    return 0;
}
