#include "DeliveryManagementSystem.h"

int main() {
    DeliveryManagementSystem deliverySystem;

    Delivery delivery1("Item 1", "A" , "B", "2023-07-01 10:00 AM");
    Delivery delivery2("Item 2", "B", "C", "2023-07-02 2:00 PM");
    deliverySystem.registerDelivery(delivery1);
    deliverySystem.registerDelivery(delivery2);

    User user1("Joe", "joe@example.com");
    User user2("Ann", "ann@example.com");
    deliverySystem.registerUser(user1);
    deliverySystem.registerUser(user2);

    deliverySystem.trackDeliveryStatus("Item 1");
    deliverySystem.trackDeliveryStatus("Item 2");

    deliverySystem.updateDeliveryStatus("Item 1", DeliveryStatus::InTransit);
    deliverySystem.updateDeliveryStatus("Item 2", DeliveryStatus::Delivered);

    deliverySystem.generateReceipt(delivery1);
    deliverySystem.generateReceipt(delivery2);

    return 0;
}
