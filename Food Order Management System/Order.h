#ifndef FOOD_ORDER_MANAGEMENT_SYSTEM_ORDER_H
#define FOOD_ORDER_MANAGEMENT_SYSTEM_ORDER_H
#include "MenuItem.h"
#include <vector>
#include <ctime>

class Order {
private:
    std::string customerName;
    std::vector<MenuItem> items;
    std::string status;
    time_t orderTime;
public:
    Order(const std::string& customerName, const std::vector<MenuItem>& items) {
        this->customerName = customerName;
        this->items = items;
        status = "Preparing";
        orderTime = time(nullptr);
    }

    std::string getCustomerName() const {
        return customerName;
    }

    const std::vector<MenuItem> getItems() const {
        return items;
    }

    std::string getStatus() const {
        return status;
    }

    std::string getOrderTime() const{
        return std::string(ctime(&orderTime));
    }

    void updateStatus(const std::string& newStatus) {
        status = newStatus;
    }

    double getTotalAmount() const {
        double total = 0.0;
        for(auto& item : items) {
            total += item.getPrice();
        }
        return total;
    }
};


#endif //FOOD_ORDER_MANAGEMENT_SYSTEM_ORDER_H
