#ifndef EXPENSE_TRACKER_EXPENSE_H
#define EXPENSE_TRACKER_EXPENSE_H
#include <iostream>

class Expense {
    std::string category;
    double amount;
    std::string description;
    std::string dataTime;
public:
    Expense(const std::string &category, double amount, const std::string &description, const std::string &dataTime)
            : category(category), amount(amount), description(description), dataTime(dataTime) {}

    const std::string &getCategory() const {
        return category;
    }

    double getAmount() const {
        return amount;
    }

    const std::string &getDescription() const {
        return description;
    }

    const std::string &getDataTime() const {
        return dataTime;
    }
};
#endif //EXPENSE_TRACKER_EXPENSE_H
