#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

float cashFlow(float income, float spending) {
    float cashFlow = income - spending;
    return cashFlow;
}

float average(float spending) {
    float average = spending / 30.0;
    return average;
}

string totalEachMonth(string month, float spending) {
    if (month == '1')
    totalEachMonth[1-1][1] = to_string(stof(totalEachMonth[1 - 1][1]) + spending);
    if (month == '2')
    totalEachMonth[2-1][2] = to_string(stof(totalEachMonth[2 - 1][1]) + spending);
    if (month == '3')
    totalEachMonth[3-1][3] = to_string(stof(totalEachMonth[3 - 1][1]) + spending);
    if (month == '4')
    totalEachMonth[4-1][4] = to_string(stof(totalEachMonth[4 - 1][1]) + spending);
    if (month == '5')
    totalEachMonth[5-1][5] = to_string(stof(totalEachMonth[5 - 1][1]) + spending);
    if (month == '6')
    totalEachMonth[6-1][6] = to_string(stof(totalEachMonth[6 - 1][1]) + spending);
    if (month == '7')
    totalEachMonth[7-1][7] = to_string(stof(totalEachMonth[7 - 1][1]) + spending);
    if (month == '8')
    totalEachMonth[8-1][8] = to_string(stof(totalEachMonth[8 - 1][1]) + spending);
    if (month == '9')
    totalEachMonth[9-1][9] = to_string(stof(totalEachMonth[9 - 1][1]) + spending);
    if (month == '10')
    totalEachMonth[10-1][10] = to_string(stof(totalEachMonth[10 - 1][1]) + spending);
    if (month == '11')
    totalEachMonth[11-1][11] = to_string(stof(totalEachMonth[11 - 1][1]) + spending);
    if (month == '12')
    totalEachMonth[12-1][12] = to_string(stof(totalEachMonth[12 - 1][1]) + spending);

    return totalEachMonth;
}

int main() {
    int months, categorySpend;
    float income, spending, flowOfCash, averageSpending;
    char ready;
    string username;
    string categorySpendData[10][2] = {{"Food", "0"}, {"Housing", "0"}, {"Utilities", "0"}, {"Transportation", "0"}, {"Clothing", "0"}, {"Health Care", "0"}, {"Entertainment", "0"}, {"Personal Care", "0"}, {"Education", "0"}, {"Miscellaneous", "0"}};

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
    // prompt user to start the program or not
    cout << "Are you ready to start the program? (Y/N): ";
    cin >> ready;
    // make the prompt case insensitive
    ready = toupper(ready);

    while (ready == 'Y') {
        // prompt user to enter the month
        cout << " 1. January    2. February     3. March " << endl;
        cout << " 4. April      5. May          6. June " << endl;
        cout << " 7. July       8. August       9. September " << endl;
        cout << " 10. October   11. November    12. December " << endl;
        cout << "Enter the month you want to record: ";
        cin >> months;

        // prompt user to enter the income
        cout << "Enter your income: RM ";
        cin >> income;

        // prompt user to enter the spending
        cout << " 1. Food       2. Housing          3. Utilities        4. Transportation " << endl;
        cout << " 5. Clothing   6. Health Care      7. Entertainment    8. Personal Care " << endl;
        cout << " 9. Education  10. Miscellaneous " << endl;
        cout << " Choose category for your spending: ";
        cin >> categorySpend;

        // prompt user to enter the spending
        cout << "Enter your spending: RM ";
        cin >> spending;

    
        switch (categorySpend) {
            case 1:
                categorySpendData[0][1] = to_string(stof(categorySpendData[0][1]) + spending);
                break;
            case 2:
                categorySpendData[1][1] = to_string(stof(categorySpendData[1][1]) + spending);
                break;
            case 3:
                categorySpendData[2][1] = to_string(stof(categorySpendData[2][1]) + spending);
                break;
            case 4:
                categorySpendData[3][1] = to_string(stof(categorySpendData[3][1]) + spending);
                break;
            case 5:
                categorySpendData[4][1] = to_string(stof(categorySpendData[4][1]) + spending);
                break;
            case 6:
                categorySpendData[5][1] = to_string(stof(categorySpendData[5][1]) + spending);
                break;
            case 7:
                categorySpendData[6][1] = to_string(stof(categorySpendData[6][1]) + spending);
                break;
            case 8:
                categorySpendData[7][1] = to_string(stof(categorySpendData[7][1]) + spending);
                break;
            case 9:
                categorySpendData[8][1] = to_string(stof(categorySpendData[8][1]) + spending);
                break;
            case 10:
                categorySpendData[9][1] = to_string(stof(categorySpendData[9][1]) + spending);
                break;
            default:
                cout << "Invalid input." << endl;
                break;
        }

        flowOfCash = cashFlow(income, spending);
        cout << fixed << showpoint;
        cout << "Your cash flow for this month is: RM " << setprecision(2) << flowOfCash << endl;
        if (flowOfCash > 0) {
            cout << "You have a positive cash flow for this month." << endl;
        } else if (flowOfCash < 0) {
            cout << "You have a negative cash flow for this month. Please make sure to plan your budget more carefully" << endl;
        } else {
            cout << "You have a zero cash flow for this month. Please make sure to plan your budget more carefully" << endl;
        }

        averageSpending = average(spending);
        cout << fixed << showpoint;
        cout << "Your average daily spending for this month is: RM " << setprecision(2) << averageSpending << endl;
        //to show the average spending for each month choose by the user

        cout << "Do you want to continue? (Y/N): ";
        cin >> ready;
        ready = toupper(ready);
        system("cls");
    }
    cout << fixed << showpoint;
    cout << "Your spending for each category: " << setprecision(2) << endl;
    for (int i = 0; i < 10; i++) {

        cout << categorySpendData[i][0] << ": RM " << fixed << setprecision(2) << stof(categorySpendData[i][1]) << endl;/*display on how much
        you spend on each category*/
    }

    cout << endl;
    string spendMost;
    float spendMostValue = 0;
    for (int i = 0; i < 10; i++) {
        if (stof(categorySpendData[i][1]) > spendMostValue) {
            spendMostValue = stof(categorySpendData[i][1]);
            spendMost = categorySpendData[i][0];
        }
    }

    cout << "You spend the most on " << spendMost << " with RM " << spendMostValue << endl;

    cout << "\nThank you for using our program." << endl;
    system("pause");

    return 0;
}
