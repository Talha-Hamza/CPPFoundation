#include <iostream>
using namespace std;

int main()
{
    int total_income;
    double tax = 0.0;

    cout << "Enter the total amount of drachmas: ";
    cin >> total_income;

    if (total_income <= 10000) {
        // First 10,000 drachmas of income are taxed at 0%
        tax = 0;
    } else if (total_income <= 30000) {
        // Next 20,000 drachmas of income are taxed at 10%
        tax = (total_income - 10000) * 0.10;
    } else if (total_income <= 70000) {
        // Next 40,000 drachmas of income are taxed at 20%
        tax = 20000 * 0.10 + (total_income - 30000) * 0.20;
    } else {
        // Drachmas after 70,000 are taxed at 30%
        tax = 20000 * 0.10 + 40000 * 0.20 + (total_income - 70000) * 0.30;
    }

    cout << "Tax amount: " << tax << " drachmas" << endl;

    return 0;
}
