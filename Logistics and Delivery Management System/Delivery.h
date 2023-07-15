#ifndef LOGISTICS_AND_DELIVERY_MANAGEMENT_SYSTEM_DELIVERY_H
#define LOGISTICS_AND_DELIVERY_MANAGEMENT_SYSTEM_DELIVERY_H
#include <iostream>

enum class DeliveryStatus {
    Pending,
    InTransit,
    Delivered
};

class Delivery {
    std::string item;
    std::string origin;
    std::string destination;
    std::string estimatedDeliveryTime;
    DeliveryStatus deliveryStatus;
public:
    Delivery(const std::string &item, const std::string &origin, const std::string &destination,
             const std::string &estimatedDeliveryTime)
            : item(item), origin(origin),
              destination(destination),
              estimatedDeliveryTime(estimatedDeliveryTime),
              deliveryStatus(DeliveryStatus::Pending) {}

    const std::string &getItem() const {
        return item;
    }

    const std::string &getOrigin() const {
        return origin;
    }

    const std::string &getDestination() const {
        return destination;
    }

    const std::string &getEstimatedDeliveryTime() const {
        return estimatedDeliveryTime;
    }

    DeliveryStatus getDeliveryStatus() const {
        return deliveryStatus;
    }

    void setDeliveryStatus(DeliveryStatus status) {
        deliveryStatus = status;
    }
};


#endif //LOGISTICS_AND_DELIVERY_MANAGEMENT_SYSTEM_DELIVERY_H
