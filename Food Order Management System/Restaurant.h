#ifndef FOOD_ORDER_MANAGEMENT_SYSTEM_RESTAURANT_H
#define FOOD_ORDER_MANAGEMENT_SYSTEM_RESTAURANT_H
#include "MenuItem.h"

class Restaurant {
        private:
        std::string name;
        std::vector<MenuItem> menu;
        std::string location;
        public:
        Restaurant(const std::string& name, const std::string& location)
        :name(name), location(location){}

        void addMenu(const MenuItem& item) {
            menu.push_back(item);
        }

        const std::string &getName() const {
            return name;
        }

        const std::string &getLocation() const {
            return location;
        }

        void printMenu() const {
            std::cout << "Menu for " << name << std::endl;
            std::cout << "---------------" << std::endl;
            for(const auto& item : menu) {
                std::cout << "Item: " << item.getName() << std::endl;
                std::cout << "Description: " << item.getDescription() << std::endl;
                std::cout << "Price: $" << item.getPrice() << std::endl;
            }
        }

        const std::vector<MenuItem> getMenu() const {
            return menu;
        }
};

#endif //FOOD_ORDER_MANAGEMENT_SYSTEM_RESTAURANT_H
