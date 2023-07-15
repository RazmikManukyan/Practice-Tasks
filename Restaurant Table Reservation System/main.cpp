#include "ReservationSystem.h"

int main() {
    ReservationSystem reservationSystem;

    reservationSystem.registerTable(Table(1, 4));
    reservationSystem.registerTable(Table(2, 2));
    reservationSystem.registerTable(Table(3, 6));

    reservationSystem.registerUser(User("Joe", "joe@example.com"));
    reservationSystem.registerUser(User("Ann", "ann@example.com"));

    reservationSystem.bookTable(reservationSystem.getUsers()[0], 2, "2023-07-09");
    reservationSystem.bookTable(reservationSystem.getUsers()[1], 4, "2023-07-09");
    reservationSystem.bookTable(reservationSystem.getUsers()[0], 6, "2023-07-10");

    reservationSystem.printReservationReport("2023-07-09");
    reservationSystem.saveReservationReportToFile("2023-07-09", "reservation_report.txt");


    return 0;
}
