#include "ParkingLotManagementSystem.h"

int main() {
    ParkingLotManagementSystem parkingSystem;

    ParkingSpace parkingSpace1("A1", ParkingSpaceSize::Compact);
    ParkingSpace parkingSpace2("B1", ParkingSpaceSize::Regular);
    ParkingSpace parkingSpace3("C1", ParkingSpaceSize::Large);
    parkingSystem.registerParkingSpace(parkingSpace1);
    parkingSystem.registerParkingSpace(parkingSpace2);
    parkingSystem.registerParkingSpace(parkingSpace3);

    User user1("Joe", ParkingSpaceSize::Compact);
    User user2("Ann", ParkingSpaceSize::Regular);
    parkingSystem.registerUser(user1);
    parkingSystem.registerUser(user2);

    parkingSystem.reserveParkingSpace("A1", "Joe");
    parkingSystem.reserveParkingSpace("B1", "Ann");

    parkingSystem.calculateParkingFee("A1", 2.5);
    parkingSystem.calculateParkingFee("B1", 3);

    parkingSystem.vacateParkingSpace("A1");
    parkingSystem.vacateParkingSpace("C1");

    parkingSystem.generateParkingLotReport("parking_lot_report.txt");


    return 0;
}
