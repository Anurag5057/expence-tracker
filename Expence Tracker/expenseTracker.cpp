#include <iostream>
#include <vector>
#include <map>
#include <string>

class Expense {
public:
    Expense(const std::string& description, double amount)
        : description(description), amount(amount) {}

    std::string getDescription() const {
        return description;
    }

    double getAmount() const {
        return amount;
    }

private:
    std::string description;
    double amount;
};

class ExpensesTracker {
public:
    void addExpense(const std::string& date, const Expense& expense) {
        expenses[date].push_back(expense);
    }

    void displayExpenses() const {
        if (expenses.empty()) {
            std::cout << "No expenses recorded.\n";
        } else {
            std::cout << "Expense List:\n";
            double total = 0.0;
            for (const auto& entry : expenses) {
                std::cout << "Date: " << entry.first << "\n";
                for (const auto& expense : entry.second) {
                    std::cout << "- " << expense.getDescription() << " ($" << expense.getAmount() << ")\n";
                    total += expense.getAmount();
                }
                std::cout << "Total Expenses for the Day: $" << total << "\n";
                total = 0.0;
            }
        }
    }

private:
    std::map<std::string, std::vector<Expense>> expenses;
};

int main() {
    ExpensesTracker tracker;

    int month, day;
    std::string description;
    double amount;

    std::cout << "Expense Tracker\n";

    std::cout << "Enter the month (1-12): ";
    std::cin >> month;

    for (day = 1; day <= 31; ++day) {
        std::cout << "\nDate: " << month << "/" << day << "\n";

        char choice;
        do {
            std::cout << "Enter expense description: ";
            std::cin.ignore();
            std::getline(std::cin, description);

            std::cout << "Enter expense amount: $";
            std::cin >> amount;

            tracker.addExpense(std::to_string(month) + "/" + std::to_string(day), Expense(description, amount));

            std::cout << "Add another expense for the day? (Y/N): ";
            std::cin >> choice;

        } while (choice == 'Y' || choice == 'y');
    }

    // Display all expenses
    tracker.displayExpenses();

    return 0;
}
