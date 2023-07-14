#ifndef EXPENSE_TRACKER_EXPENSETRACKER_H
#define EXPENSE_TRACKER_EXPENSETRACKER_H
#include <vector>
#include <sstream>
#include "Expense.h"
#include <iomanip>

class ExpenseTracker {
    std::vector<Expense> expenses;
public:
    void addExpense(const Expense& expense) {
        expenses.push_back(expense);
    }

    void viewAllExpenses() const {
        if(expenses.empty()) {
            std::cout << "No expenses found." << std::endl;
            return;
        }
        std::cout << "All expenses:" << std::endl;
        for(const auto& expense : expenses) {
            std::cout << "Category: " << expense.getCategory() << std::endl;
            std::cout << "Amount: $" << expense.getAmount() << std::endl;
            std::cout << "Description: " << expense.getDescription() << std::endl;
            std::cout << "Datetime: " << expense.getDataTime() << std::endl;
            std::cout << "-----------------------------" << std::endl;
        }
    }

    void generateCategorySummaries() const {
        if (expenses.empty()) {
            return;
        }
        std::cout << "Category Summaries:" << std::endl;
        std::vector<std::string> categories;

        for(const auto& expense : expenses) {
            if(std::find(categories.begin(), categories.end(), expense.getCategory()) == categories.end()) {
                categories.push_back(expense.getCategory());
            }
        }
        for(const auto& category : categories) {
            double totalAmount = 0.0;
            for(const auto& expense : expenses) {
                if(expense.getCategory() == category) {
                    totalAmount += expense.getAmount();
                }
            }
            std::cout << "Category: " << category << std::endl;
            std::cout << "Amount: " << totalAmount << std::endl;
            std::cout << "-------------------------------" << std::endl;
        }
    }

    void generateWeeklySpendingReport() const {
        if(expenses.empty()) {
            std::cout << "No expenses found." << std::endl;
            return;
        }
        time_t currentTime = time(nullptr);
        tm* localTime = localtime(&currentTime);
        int currentWeak = localTime->tm_yday / 7;

        std::cout << "Weekly Spending Report:" << std::endl;
        for(const auto& expense : expenses) {
            tm expenseTime;
            std::istringstream ss(expense.getDataTime());
            ss >> std::get_time(&expenseTime, "%Y-%m-%d %H:%M:%S");
            int expenseWeak = expenseTime.tm_yday / 7;

            if(currentWeak == expenseWeak) {
                std::cout << "Category: " << expense.getCategory() << std::endl;
                std::cout << "Amount: $" << expense.getAmount() << std::endl;
                std::cout << "Description: " << expense.getDescription() << std::endl;
                std::cout << "Datetime: " << expense.getDataTime() << std::endl;
                std::cout << "-----------------------------" << std::endl;
            }
        }
    }

    void generateMonthlySpendingReport() const {
        if (expenses.empty()) {
            std::cout << "No expenses found." << std::endl;
            return;
        }

        std::time_t currentTime = std::time(nullptr);
        std::tm* localTime = std::localtime(&currentTime);
        int currentMonth = localTime->tm_mon;

        std::cout << "Monthly Spending Report:" << std::endl;
        for (const auto& expense : expenses) {
            std::tm expenseTime;
            std::istringstream ss(expense.getDataTime());
            ss >> std::get_time(&expenseTime, "%Y-%m-%d %H:%M:%S");
            int expenseMonth = expenseTime.tm_mon;

            if (currentMonth == expenseMonth) {
                std::cout << "Category: " << expense.getCategory() << std::endl;
                std::cout << "Amount: $" << expense.getAmount() << std::endl;
                std::cout << "Description: " << expense.getDescription() << std::endl;
                std::cout << "Datetime: " << expense.getDataTime() << std::endl;
                std::cout << "-----------------------------" << std::endl;
            }
        }
    }
};
#endif //EXPENSE_TRACKER_EXPENSETRACKER_H
