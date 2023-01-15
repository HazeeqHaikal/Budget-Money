#include <iostream>
#include <string>

using namespace std;

float cashFlow(float income, float spending) {
    float cashFlow = income - spending;
    return cashFlow;
}

int main() {
    int months, categorySpend;
    float income, spending, flowOfCash;

    cout << "1. January\n2. February\n3. March\n4. April\n5. May\n6. June\n7. July\n8. August\n9. September\n10. October\n11. November\n12. December\nChoose a month: ";
    cin >> months;

    cout << "Enter your income: RM ";
    cin >> income;

    cout << "1. Food\n2. Housing\n3. Utilities\n4. Transportation\n5. Clothing\n6. Health Care\n7. Entertainment\n8. Personal Care\n9. Education\n10. Miscellaneous\nChoose category for your spending: ";
    cin >> categorySpend;

    cout << "Enter your spending: RM ";
    cin >> spending;

    flowOfCash = cashFlow(income, spending);
    cout << "Your cash flow for this month is: RM " << flowOfCash << endl;

    return 0;
}