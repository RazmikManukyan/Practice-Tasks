#ifndef FOOD_ORDER_MANAGEMENT_SYSTEM_MENUITEM_H
#define FOOD_ORDER_MANAGEMENT_SYSTEM_MENUITEM_H
#include <iostream>
#include <vector>

class MenuItem {
private:
    std::string name;
    std::string description;
    double price;
public:
    MenuItem(const std::string &name, const std::string &description, double price)
            : name(name), description(description), price(price) {}

    const std::string &getName() const {
        return name;
    }

    const std::string &getDescription() const {
        return description;
    }

    double getPrice() const {
        return price;
    }
};

#endif //FOOD_ORDER_MANAGEMENT_SYSTEM_MENUITEM_H
