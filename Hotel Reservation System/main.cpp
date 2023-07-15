#include "Hotel.h"

int main() {
    Hotel hotel;

    Room room1(101, "Single");
    Room room2(202, "Double");
    Room room3(333, "Suite");

    hotel.registerRoom(room1);
    hotel.registerRoom(room2);
    hotel.registerRoom(room3);

    Customer customer("Joe", "joe@example.com");

    Room* availableRoom = hotel.findAvailableRoomByType("Single");
    if(availableRoom != nullptr) {
        double totalCost = 100;
        Reservation reservation = hotel.bookRoom(*availableRoom, customer, totalCost);

        reservation.printBill();

        saveBillToFile("file.txt", reservation);
    } else {
        std::cout << "No available Room of the requested type: " << std::endl;
    }
    return 0;
}
