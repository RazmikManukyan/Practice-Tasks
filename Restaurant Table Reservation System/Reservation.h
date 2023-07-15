#ifndef RESTAURANT_TABLE_RESERVATION_SYSTEM_RESERVATION_H
#define RESTAURANT_TABLE_RESERVATION_SYSTEM_RESERVATION_H
#include "Table.h"
#include "User.h"

class Reservation{
private:
    const Table& table;
    const User& user;
    std::string reservationDate;
public:
    Reservation(const Table &table, const User &user, const std::string &reservationDate)
            : table(table), user(user), reservationDate(reservationDate) {}

    const Table &getTable() const {
        return table;
    }

    const User &getUser() const {
        return user;
    }

    const std::string &getReservationDate() const {
        return reservationDate;
    }
};

#endif //RESTAURANT_TABLE_RESERVATION_SYSTEM_RESERVATION_H
