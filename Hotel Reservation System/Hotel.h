#ifndef HOTELRS_HOTEL_H
#define HOTELRS_HOTEL_H
#include <vector>
#include "Room.h"
#include "Reservation.h"

class Hotel{
private:
    std::vector<Room> rooms;
    std::vector<Reservation> reservations;
public:
    void registerRoom(const Room& room) {
        rooms.push_back(room);
    }

    Room* findAvailableRoomByType(const std::string& type) {
        for(auto& room : rooms) {
            if(room.getRoomType() == type && room.getAvailability())
                return &room;
        }
        return nullptr;
    }

    Reservation bookRoom(Room& room, const Customer& customer, double price) {
        room.setAvailability(false);
        Reservation reservation1(room, customer, price);
        reservations.push_back(reservation1);
        return reservation1;
    }


};

#endif //HOTELRS_HOTEL_H
