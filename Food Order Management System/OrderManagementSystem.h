#ifndef FOOD_ORDER_MANAGEMENT_SYSTEM_ORDERMANAGEMENTSYSTEM_H
#define FOOD_ORDER_MANAGEMENT_SYSTEM_ORDERMANAGEMENTSYSTEM_H
#include "Restaurant.h"
#include <vector>
#include "Customer.h"
#include "Order.h"
#include <fstream>

class OrderManagementSystem {
private:
    std::vector<Restaurant> restaurants;
    std::vector<Customer> customers;
    std::vector<Order> orders;
public:
    void registerRestaurant(const Restaurant& restaurant) {
        restaurants.push_back(restaurant);
    }

    void registerCustomer(const Customer& customer) {
        customers.push_back(customer);
    }

    const std::vector<Order> &getOrders() const {
        return orders;
    }

    void placeOrder(const std::string& customerName, const std::string& restaurantName, const std::vector<std::string>& itemsName) {
        Restaurant* restaurant = nullptr;
        Customer* customer = nullptr;
        std::vector<MenuItem> items;

        for(auto& r : restaurants) {
            if(r.getName() == restaurantName){
                restaurant = &r;
                break;
            }
        }

        for(auto& c : customers) {
            if(c.getName() == customerName) {
                customer = &c;
                break;
            }
        }

        if(restaurant) {
            const std::vector<MenuItem>& menu = restaurant->getMenu();
            for(const std::string& itemName : itemsName) {
                for(const auto& item : menu) {
                    if(item.getName() == itemName) {
                        items.push_back(item);
                        break;
                    }
                }
            }
        }

        if(restaurant and customer and !items.empty()) {
            Order order(customerName, items);
            orders.push_back(order);
            std::cout << "Order placed successfully!" << std::endl;
        } else {
            std::cout << "Order placement failed. Please check the provided details." << std::endl;
        }
    }

    void trackOrder(const std::string& customerName) const {
        std::cout << "Order trucking for: " << customerName << std::endl;
        std::cout << "--------------------" << std::endl;
        bool orderFound = false;
        for(const auto& order : orders) {
            if(order.getCustomerName() == customerName) {
                std::cout << "Order time: " << order.getOrderTime() << std::endl;
                std::cout << "Status: " << order.getStatus() << std::endl;
                std::cout << "Order items: " << std::endl;
                for(const auto& item : order.getItems()) {
                    std::cout << "Items: " << item.getName() << std::endl;
                }
                std::cout << std::endl;
                orderFound = true;
            }
        }
        if(!orderFound) {
            std::cout << "No orders found for the provided customer." << std::endl;
        }
    }

    void generateBill(const Order& order) const {
        std::cout << "Bill for Order" << std::endl;
        std::cout << "---------------" << std::endl;
        std::cout << "Customer name: " << order.getCustomerName() << std::endl;
        std::cout << "Orders item: " << std::endl;
        for(const auto& item : order.getItems()) {
            std::cout << "Item: " << item.getName() << std::endl;
        }
        std::cout << "Total amount: $" << order.getTotalAmount() << std::endl;
        std::cout << std::endl;
    }

    void saveBillToFile(const Order& order) const {
        std::string filename = order.getCustomerName() + "_bill.txt";
        std::ofstream file(filename);
        if(file.is_open()) {
            file << "Bill for Order" << std::endl;
            file << "---------------" << std::endl;
            file << "Customer name: " << order.getCustomerName() << std::endl;
            file << "Orders item: " << std::endl;
            for(const auto& item : order.getItems()) {
                file << "Item: " << item.getName() << std::endl;
            }
            file << "Total amount: $" << order.getTotalAmount() << std::endl;
            file << std::endl;
            file.close();
            std::cout << "Bill saved to file: " << filename << std::endl;
        } else {
            std::cout << "Unable to open: " << std::endl;
        }
    }
};



#endif //FOOD_ORDER_MANAGEMENT_SYSTEM_ORDERMANAGEMENTSYSTEM_H
