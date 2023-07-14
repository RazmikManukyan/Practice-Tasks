#include "OrderManagementSystem.h"

int main() {
    OrderManagementSystem orderManagementSystem;

    Restaurant restaurant1("Restaurant A", "Location A");
    restaurant1.addMenu(MenuItem("Item1", "Description1", 10.0));
    restaurant1.addMenu(MenuItem("Item2", "Description2", 15.0));
    orderManagementSystem.registerRestaurant(restaurant1);


    Restaurant restaurant2("Restaurant B", "Location B");
    restaurant2.addMenu(MenuItem("Item3", "Description3", 12.0));
    restaurant2.addMenu(MenuItem("Item4", "Description4", 18.0));
    orderManagementSystem.registerRestaurant(restaurant2);

    Customer customer1("Joe", "joe@example.com", "Credit card");
    Customer customer2("Jane", "jane@example.com", "Cash");
    orderManagementSystem.registerCustomer(customer1);
    orderManagementSystem.registerCustomer(customer2);

    orderManagementSystem.placeOrder("Joe", "Restaurant A", {"Item1", "Item2"});
    orderManagementSystem.placeOrder("Jane", "Restaurant B", {"Item3"});

    orderManagementSystem.trackOrder("Joe");
    orderManagementSystem.trackOrder("Jane");

    const std::vector<Order>& orders = orderManagementSystem.getOrders();
    for(const auto& order : orders) {
        orderManagementSystem.generateBill(order);
        orderManagementSystem.saveBillToFile(order);
    }
    return 0;
}
