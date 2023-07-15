#ifndef RESTAURANT_TABLE_RESERVATION_SYSTEM_TABLE_H
#define RESTAURANT_TABLE_RESERVATION_SYSTEM_TABLE_H

class Table {
private:
    int tableNumber;
    int seatingCapacity;
    bool isAvailable;
public:
    Table(int tableNumber, int seatingCapacity)
            :tableNumber(tableNumber), seatingCapacity(seatingCapacity), isAvailable(true){}

    int getTableNumber() const {
        return tableNumber;
    }

    int getSeatingCapacity() const {
        return seatingCapacity;
    }

    bool getAvailability() const {
        return isAvailable;
    }

    void setAvailability(bool a) {
        isAvailable = a;
    }
};

#endif //RESTAURANT_TABLE_RESERVATION_SYSTEM_TABLE_H
