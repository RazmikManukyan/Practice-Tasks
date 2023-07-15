#ifndef RESTAURANT_TABLE_RESERVATION_SYSTEM_RESERVATIONSYSTEM_H
#define RESTAURANT_TABLE_RESERVATION_SYSTEM_RESERVATIONSYSTEM_H
#include "Reservation.h"
#include <vector>

class ReservationSystem {
private:
    std::vector<Table> tables;
    std::vector<User> users;
    std::vector<Reservation> reservations;
public:
    const std::vector<Table> &getTables() const {
        return tables;
    }

    const std::vector<User> &getUsers() const {
        return users;
    }

    const std::vector<Reservation> &getReservations() const {
        return reservations;
    }

    void registerTable(const Table& table) {
        tables.push_back(table);
    }
    void registerUser(const User& user) {
        users.push_back(user);
    }

    void bookTable(const User& user, int seatingCapacity, const std::string& reservationDate) {
        Table* selectedTable = nullptr;
        for(auto& table : tables) {
            if(table.getSeatingCapacity() == seatingCapacity && table.getAvailability()) {
                selectedTable = &table;
                break;
            }
        }

        if(selectedTable) {
            selectedTable->setAvailability(false);
            Reservation reservation(*selectedTable, user, reservationDate);
            reservations.push_back(reservation);
            std::cout << "Table: " << selectedTable->getTableNumber()
                      << "has been successfully reserved for " << user.getName()
                      << " on " << reservation.getReservationDate() << std::endl;
        } else {
            std::cout << "No available table with the desired seating capacity." << std::endl;
        }
    }

    void printReservationReport(const std::string& date) const {
        std::cout << "Reservation Report for " << date << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        bool reservationFound = false;

        for(auto& reservation : reservations) {
            if(reservation.getReservationDate() == date) {
                const Table& table = reservation.getTable();
                const User& user = reservation.getUser();
                std::cout << "Table: " << table.getTableNumber()
                          << " - " << user.getName()
                          << " (" << user.getContactInfo() <<") " << std::endl;
                reservationFound = true;
            }
        }
        if(!reservationFound) {
            std::cout << "No reservations found for the provided date." << std::endl;
        }
    }

    void saveReservationReportToFile(const std::string& date, const std::string& filename) const {
        std::ofstream file(filename);
        if(file.is_open()) {
            file << "Reservation Report for " << date << std::endl;
            file << "----------------------------------------" << std::endl;

            bool reservationFound = false;
            for(auto& reservation : reservations) {
                const Table& table = reservation.getTable();
                const User& user = reservation.getUser();

                file << "Table: " << table.getTableNumber()
                     << " - " << user.getName()
                     << " (" << user.getContactInfo() << ") " << std::endl;
                reservationFound = true;
            }
            if(!reservationFound) {
                file << "No reservations found for the provided date." << std::endl;
            }
            file.close();
            std::cout << "Reservation report saved to file: " << filename << std::endl;
        } else {
            std::cout << "Unable to open file: " << filename << std::endl;
        }
    }
};

#endif //RESTAURANT_TABLE_RESERVATION_SYSTEM_RESERVATIONSYSTEM_H
