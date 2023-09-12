#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

float cashFlow(float income, float spending) {
    float cashFlow = income - spending;
    return cashFlow;
}

float average(float spending) {
    float average = spending / 30.0;
    return average;
}

int main() {
    int months, categorySpend, ready;
    float income, spending, flowOfCash, averageSpending;
    string username;
    char prompt;
    string totalIncomeEachMonth[12][2] = {
        {"Jan", "0"}, {"Feb", "0"}, {"Mar", "0"}, {"Apr", "0"}, {"May", "0"}, {"Jun", "0"}, {"Jul", "0"}, {"Aug", "0"}, {"Sep", "0"}, {"Oct", "0"}, {"Nov", "0"}, {"Dec", "0"}};
    string totalEachMonth[12][2] = {{"Jan", "0"}, {"Feb", "0"}, {"Mar", "0"}, {"Apr", "0"}, {"May", "0"}, {"Jun", "0"}, {"Jul", "0"}, {"Aug", "0"}, {"Sep", "0"}, {"Oct", "0"}, {"Nov", "0"}, {"Dec", "0"}};
    string categorySpendData[10][2] = {
        {"Food", "0"}, {"Housing", "0"}, {"Utilities", "0"}, {"Transportation", "0"}, {"Clothing", "0"}, {"Health Care", "0"}, {"Entertainment", "0"}, {"Personal Care", "0"}, {"Education", "0"}, {"Miscellaneous", "0"}};

    cout << "Welcome to our program." << endl;
    cout << "Enter your name: ";

    getline(cin, username);

    // capitalize each first letter of the name
    for (int i = 0; i < username.length(); i++) {
        if (i == 0) {
            username[i] = toupper(username[i]);
        } else if (username[i] == ' ') {
            username[i + 1] = toupper(username[i + 1]);
        }
    }

    cout << "\nHello, " << username << " " << endl;

    cout << "Do you want to start the program? Enter 'Y' to continue: ";
    cin >> prompt;
    prompt = toupper(prompt);

    while (prompt == 'Y') {
        // prompt user to enter the month
        cout << " 1. January    2. February     3. March " << endl;
        cout << " 4. April      5. May          6. June " << endl;
        cout << " 7. July       8. August       9. September " << endl;
        cout << " 10. October   11. November    12. December " << endl;
        cout << "Enter the month you want to record: ";
        cin >> months;
        cout << endl;
        if (months > 12 || months < 1 || totalEachMonth[months - 1][1] != "0") {
            cout << "Invalid month" << endl;
            break;
        } else {
            cout << "Enter your income: RM ";
            cin >> income;
        }

        totalIncomeEachMonth[months - 1][1] = to_string(income);

        // prompt user to enter the spending
        cout << " 1. Food       2. Housing          3. Utilities       "
                " 4. "
                "Transportation"
             << endl;
        cout << " 5. Clothing   6. Health Care      7. Entertainment   "
                " 8. "
                "Personal Care"
             << endl;
        cout << " 9. Education  10. Miscellaneous " << endl;
        cout << " Choose category for your spending: ";
        cin >> categorySpend;

        // prompt user to enter the spending
        cout << "Enter your spending: RM ";
        cin >> spending;
        if (spending < 1 || spending > 10) {
            cout << "Invalid input" << endl;
            break;
        } else {
            categorySpendData[categorySpend - 1][1] =
                to_string(stof(categorySpendData[categorySpend - 1][1]) +
                          spending);
        }

        if (months < 1 || months > 12) {
            cout << "Invalid month" << endl;
            break;
        } else {
            totalEachMonth[months - 1][1] =
                to_string(stof(totalEachMonth[months - 1][1]) + spending);
        }

        cout << endl;
        cout << "Do you want to record another spending? (Y/N): ";
        cin >> prompt;
        prompt = toupper(prompt);

        if (prompt == 'N') {
        }
    }

    char promptCheck = 'Y';
    while (promptCheck == 'Y') {
        cout << "1. Check your spending for each category" << endl;
        cout << "2. Check your average daily spending for each month" << endl;
        cout << "3. Check your spending for each month" << endl;
        cout << "4. Check your cash flow" << endl;

        cout << "Please choose an option: ";
        cin >> ready;

        switch (ready) {
            case 1:
                cout << fixed << showpoint;
                cout << "Your spending for each category: " << setprecision(2)
                     << endl;
                for (int i = 0; i < 10; i++) {
                    cout << categorySpendData[i][0] << ": RM " << fixed
                         << setprecision(2) << stof(categorySpendData[i][1])
                         << endl;
                }
                break;
            case 2:
                cout << fixed << showpoint;
                cout << "Your average daily spending for each month: "
                     << setprecision(2) << endl;
                for (int i = 0; i < 12; i++) {
                    cout << totalEachMonth[i][0] << ": RM " << fixed
                         << setprecision(2) << stof(totalEachMonth[i][1]) / 30.0
                         << endl;
                }
                break;
            case 3:
                cout << fixed << showpoint;
                cout << "Your spending for each month: " << setprecision(2)
                     << endl;
                for (int i = 0; i < 12; i++) {
                    cout << totalEachMonth[i][0] << ": RM " << fixed
                         << setprecision(2) << stof(totalEachMonth[i][1])
                         << endl;
                }
                break;
            case 4:
                cout << " 1. January    2. February     3. March " << endl;
                cout << " 4. April      5. May          6. June " << endl;
                cout << " 7. July       8. August       9. September " << endl;
                cout << " 10. October   11. November    12. December " << endl;
                cout << "Enter the month you want to see your cash flow: ";
                cin >> months;

                flowOfCash = cashFlow(stof(totalIncomeEachMonth[months - 1][1]),
                                      stof(totalEachMonth[months - 1][1]));
                cout << fixed << showpoint;
                cout << "Your cash flow for " << totalEachMonth[months - 1][0]
                     << " is: RM " << setprecision(2) << flowOfCash << endl;
                if (flowOfCash > 0) {
                    cout << "You have a positive cash flow for this month."
                         << endl;
                } else if (flowOfCash < 0) {
                    cout << "You have a negative cash flow for this month. "
                            "Please "
                            "make sure to plan your budget more carefully"
                         << endl;
                } else {
                    cout << "You have a zero cash flow for this month. "
                            "Please "
                            "make "
                            "sure to plan your budget more carefully"
                         << endl;
                }
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
        cout << endl;
        cout << "Do you want to check another option? (Y/N): ";
        cin >> promptCheck;
        promptCheck = toupper(promptCheck);
        system("cls");
    }

    cout << "Thank you for using this program!" << endl;

    system("pause");

    return 0;
}
