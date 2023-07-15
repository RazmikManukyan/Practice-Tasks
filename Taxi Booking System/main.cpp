#include "TaxiBookingSystem.h"
#include <ctime>

int main() {
    TaxiBookingSystem bookingSystem;

    bookingSystem.registerTaxi(Taxi("T001", "Joe", "comfort"));
    bookingSystem.registerTaxi(Taxi("T002", "Jack", "business"));

    bookingSystem.registerUser(User("Ann", "ann@example.com"));
    bookingSystem.registerUser(User("Jane", "jane@example.com"));

    bookingSystem.bookTaxi(bookingSystem.getUsers()[0], 10.5, "2023-07-12 10:00:00", "2023-07-12 10:30:00");
    bookingSystem.bookTaxi(bookingSystem.getUsers()[1], 15.0, "2023-07-09 13:00", "2023-07-09 14:00");

    bookingSystem.saveRideRecipeToFile("ride_receipts.txt");


    return 0;
}
