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
    char ready;
    string end;
    string username;

    cout << "Enter your name: ";
    getline(cin, username);
    system("cls");

    // capitalize each first letter of the name
    for (int i = 0; i < username.length(); i++) {
        if (i == 0) {
            username[i] = toupper(username[i]);
        } else if (username[i] == ' ') {
            username[i + 1] = toupper(username[i + 1]);
        }
    }

    cout << "\nHello, " << username << " " << endl;
    cout << "Welcome to our program." << endl;
    cout << "Are you ready to start the program? (Y/N): ";
    cin >> ready;
    ready = toupper(ready);
    system("cls");

    while (ready == 'Y') {
        cout << " 1. January    2. February     3. March " << endl;
        cout << " 4. April      5. May          6. June " << endl;
        cout << " 7. July       8. August       9. September " << endl;
        cout << " 10. October   11. November    12. December " << endl;
        cout << "Enter the month: ";
        cin >> months;
        system("cls");

        cout << "Enter your income: RM ";
        cin >> income;
        system("cls");

        cout << " 1. Food       2. Housing          3. Utilities        4. Transportation " << endl;
        cout << " 5. Clothing   6. Health Care      7. Entertainment    8. Personal Care " << endl;
        cout << " 9. Education  10. Miscellaneous " << endl;
        cout << " Choose category for your spending: ";
        cin >> categorySpend;
        system("cls");

        cout << "Enter your spending: RM ";
        cin >> spending;
        system("cls");

        flowOfCash = cashFlow(income, spending);
        cout << "Your cash flow for this month is: RM " << flowOfCash << endl;

        cout << "Do you want to continue? (Y/N): ";
        cin >> ready;
        ready = toupper(ready);
        system("cls");
    }

    cout << "\nThank you for using our program." << endl;
    system("pause");

    return 0;
}
