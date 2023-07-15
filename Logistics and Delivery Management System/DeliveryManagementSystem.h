#ifndef LOGISTICS_AND_DELIVERY_MANAGEMENT_SYSTEM_DELIVERYMANAGEMENTSYSTEM_H
#define LOGISTICS_AND_DELIVERY_MANAGEMENT_SYSTEM_DELIVERYMANAGEMENTSYSTEM_H
#include <vector>
#include <fstream>
#include "Delivery.h"
#include "User.h"


class DeliveryManagementSystem {
    std::vector<Delivery> deliveries;
    std::vector<User> users;
public:
    void registerDelivery(const Delivery &delivery) {
        deliveries.push_back(delivery);
    }

    void registerUser(const User &user) {
        users.push_back(user);
    }

    void trackDeliveryStatus(const std::string &item) {
        std::cout << "Delivery status for item: " << item << std::endl;
        std::cout << "------------------------------" << std::endl;

        bool found = false;
        for (auto &delivery: deliveries) {
            if (delivery.getItem() == item) {
                std::cout << "Origin: " << delivery.getOrigin() << std::endl;
                std::cout << "Destination: " << delivery.getDestination() << std::endl;
                std::cout << "Estimated Delivery Time: " << delivery.getEstimatedDeliveryTime() << std::endl;
                std::cout << "Status: ";
                switch (delivery.getDeliveryStatus()) {
                    case DeliveryStatus::Pending:
                        std::cout << "Pending";
                        break;
                    case DeliveryStatus::InTransit:
                        std::cout << "In Transit";
                        break;
                    case DeliveryStatus::Delivered:
                        std::cout << "Delivered";
                        break;
                }
                std::cout << std::endl;
                std::cout << "----------------------------------" << std::endl;
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "No delivery found for item: " << item << std::endl;
        }
    }

    void updateDeliveryStatus(const std::string &item, DeliveryStatus status) {
        for (auto &delivery: deliveries) {
            if (delivery.getItem() == item) {
                delivery.setDeliveryStatus(status);
            }
        }
    }

    void generateReceipt(const Delivery &delivery) const {
        std::string filename = delivery.getItem() + "_receipt.txt";
        std::ofstream file(filename);
        if (file.is_open()) {
            file << "Delivery Receipt" << std::endl;
            file << "-------------------------------" << std::endl;
            file << "Item: " << delivery.getItem() << std::endl;
            file << "Origin: " << delivery.getOrigin() << std::endl;
            file << "Delivery: " << delivery.getDestination() << std::endl;
            file << "Estimated Delivery Time: " << delivery.getDestination() << std::endl;
            file << "Status";
            switch (delivery.getDeliveryStatus()) {
                case DeliveryStatus::Pending:
                    file << "Pending";
                    break;
                case DeliveryStatus::InTransit:
                    file << "In Transit";
                    break;
                case DeliveryStatus::Delivered:
                    file << "Delivered";
                    break;
            }
            file << std::endl;
            file.close();
            std::cout << "Receipt saved to file: " << filename << std::endl;
        } else {
            std::cout << "Unable to open the file: " << filename << std::endl;
        }
    }
};


#endif //LOGISTICS_AND_DELIVERY_MANAGEMENT_SYSTEM_DELIVERYMANAGEMENTSYSTEM_H
