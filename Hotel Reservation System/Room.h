#ifndef HOTELRS_ROOM_H
#define HOTELRS_ROOM_H
#include <iostream>

class Room{
private:
    int roomNumber;
    std::string roomType;
    bool isAvailable;
public:
    Room(int roomNumber, const std::string& roomType)
            :roomNumber(roomNumber), roomType(roomType), isAvailable(true){}

    int getRoomNumber() const {
        return roomNumber;
    }

    const std::string &getRoomType() const {
        return roomType;
    }

    bool getAvailability() const {
        return isAvailable;
    }

    void setAvailability(bool isAvailable) {
        this->isAvailable = isAvailable;
    }
};

#endif //HOTELRS_ROOM_H
