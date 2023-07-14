#include <iostream>
#include "ExpenseTracker.h"

int main() {
    ExpenseTracker expenseTracker;

    expenseTracker.addExpense(Expense("Food", 10.99, "Lunch", "2023-07-12 12:30:00"));
    expenseTracker.addExpense(Expense("Transportation", 25.50, "Taxi", "2023-07-13 08:45:00"));
    expenseTracker.addExpense(Expense("Shopping", 99.99, "New shoes", "2023-07-14 15:20:00"));

    expenseTracker.viewAllExpenses();

    expenseTracker.generateCategorySummaries();

    expenseTracker.generateWeeklySpendingReport();

    expenseTracker.generateMonthlySpendingReport();

    return 0;
}
