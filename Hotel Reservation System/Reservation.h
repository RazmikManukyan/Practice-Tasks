#ifndef HOTELRS_RESERVATION_H
#define HOTELRS_RESERVATION_H
#include "Room.h"
#include "Customer.h"
#include <fstream>

class Reservation {
private:
    Room room;
    Customer customer;
    double totalCost;
public:
    Reservation(Room &room, const Customer &customer, double totalCost)
            : room(room), customer(customer), totalCost(totalCost) {}

    const Room &getRoom() const {
        return room;
    }

    const Customer &getCustomer() const {
        return customer;
    }

    double getTotalCost() const {
        return totalCost;
    }

    void printBill() const {
        std::cout << "Reservation Bill: " << std::endl;
        std::cout << "Room number: " << room.getRoomNumber() << std::endl;
        std::cout << "Customer: " << customer.getName() << std::endl;
        std::cout << "Contact info: " << customer.getContactInfo() << std::endl;
        std::cout << "Total cost: $" << totalCost << std::endl;
    }
};

void saveBillToFile(const std::string& filename, const Reservation& reservation) {
    std::ofstream file(filename);
    if(file.is_open()) {
        file << "Reservation Bill:" << std::endl;
        file << "Room number: " << reservation.getRoom().getRoomNumber() << std::endl;
        file << "Room type: " << reservation.getRoom().getRoomType() << std::endl;
        file << "Customer: " << reservation.getCustomer().getName() << std::endl;
        file << "Contact info: " << reservation.getCustomer().getContactInfo() << std::endl;
        file << "Total cost: $" << reservation.getTotalCost() << std::endl;
        file.close();
        std::cout << "Reservation bill saved to file: " << filename << std::endl;
    } else {
        std::cout << "Unable to open the file for saving the reservation bill." << std::endl;
    }
}


#endif //HOTELRS_RESERVATION_H
