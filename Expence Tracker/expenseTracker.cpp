#include <iostream>
#include <string>
#include <map>

using namespace std;

class ExpenseTracker {
private:
    double monthlyIncome;
    map<string, double> expenseBudgets;
    map<string, double> expenseTracker;

public:
    ExpenseTracker() {
        monthlyIncome = 0.0;
    }

    void setMonthlyIncome(double income) {
        monthlyIncome = income;
    }

    void setExpenseBudget(string expenseType, double budget) {
        expenseBudgets[expenseType] = budget;
    }

    void trackExpenses(int numDays) {
        for (int day = 1; day <= numDays; ++day) {
            cout << "Day " << day << endl;

            int numExpenses;
            cout << "Enter the number of expenses for day " << day << ": ";
            cin >> numExpenses;

            for (int i = 0; i < numExpenses; ++i) {
                string expenseType;
                double amount;
                cout << "Enter the type of expense " << i+1 << ": ";
                cin >> expenseType;
                cout << "Enter the amount for expense " << i+1 << ": ";
                cin >> amount;

                expenseTracker[expenseType] += amount;
            }
        }
    }

    double calculateTotalExpenses() const {
        double totalExpenses = 0.0;
        for (const auto& expense : expenseTracker) {
            totalExpenses += expense.second;
        }
        return totalExpenses;
    }

    double calculateSavings() const {
        double totalExpenses = calculateTotalExpenses();
        return monthlyIncome - totalExpenses;
    }

    void displayResults() const {
        cout << "\nMonthly Income: $" << monthlyIncome << endl;

        cout << "\nExpense Budgets:" << endl;
        for (const auto& budget : expenseBudgets) {
            cout << budget.first << ": $" << budget.second << endl;
        }

        cout << "\nExpense Tracker for the Month:" << endl;
        for (const auto& expense : expenseTracker) {
            cout << expense.first << ": $" << expense.second << endl;
        }

        cout << "\nTotal Expenses: $" << calculateTotalExpenses() << endl;
        cout << "Savings: $" << calculateSavings() << endl;
    }
};

int main() {
    ExpenseTracker tracker;

    double monthlyIncome;
    cout << "Enter your monthly income: ";
    cin >> monthlyIncome;
    tracker.setMonthlyIncome(monthlyIncome);

    int numExpenseTypes;
    cout << "Enter the number of expense types: ";
    cin >> numExpenseTypes;

    for (int i = 0; i < numExpenseTypes; ++i) {
        string expenseType;
        double budget;
        cout << "Enter the name of expense type " << i+1 << ": ";
        cin >> expenseType;
        cout << "Enter the budget for " << expenseType << ": ";
        cin >> budget;
        tracker.setExpenseBudget(expenseType, budget);
    }

    int numDays;
    cout << "Enter the number of days in the month: ";
    cin >> numDays;

    tracker.trackExpenses(numDays);

    tracker.displayResults();

    return 0;
}
