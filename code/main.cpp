#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// The isatty() function will tell us whether standard input is piped or not.
#ifdef _WIN32
#include <io.h>
#include <windows.h>
#define isatty _isatty
#else
#include <unistd.h>
#endif

using namespace std;

float cashFlow(float income, float spending) {
    float cashFlow = income - spending;
    return cashFlow;
}

float average(float spending) {
    float average = spending / 30.0;
    return average;
}

int main(int argc, char** argv) {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    // Maximum screen height
    int max_lines = (argc == 2) ? stoi(argv[1]) : 25;
    int month, categorySpend;
    float income, spending, flowOfCash, averageSpending;
    string totalEachMonth[12][2] = {{"Jan", "0"}, {"Feb", "0"}, {"Mar", "0"}, {"Apr", "0"}, {"May", "0"}, {"Jun", "0"}, {"Jul", "0"}, {"Aug", "0"}, {"Sep", "0"}, {"Oct", "0"}, {"Nov", "0"}, {"Dec", "0"}};
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
        cin >> month;

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

        // to show the total spending for each month choose by the user
        totalEachMonth[month - 1][1] = to_string(stof(totalEachMonth[month - 1][1]) + spending);
        categorySpendData[categorySpend - 1][1] = to_string(stof(categorySpendData[categorySpend - 1][1]) + spending);

        // flowOfCash = cashFlow(income, spending);
        // cout << "Your cash flow for this month is: RM " << flowOfCash << endl;
        // if (flowOfCash > 0) {
        //     cout << "You have a positive cash flow for this month." << endl;
        // } else if (flowOfCash < 0) {
        //     cout << "You have a negative cash flow for this month. Please make sure to plan your budget more carefully" << endl;
        // } else {
        //     cout << "You have a zero cash flow for this month. Please make sure to plan your budget more carefully" << endl;
        // }

        // averageSpending = average(spending);
        // cout << "Your average spending for this month is: RM " << averageSpending << endl;
        // to show the average spending for each month choose by the user

        cout << "Do you want to continue? (Y/N): ";
        cin >> ready;
        ready = toupper(ready);
        system("cls");
    }

    // Calculate the vertical dimensions of the graph,
    // fitting it to the available space as necessary.
    double domain = max_element(0, 12);
    // double domain = *max_element(months.begin(), months.end());
    double divisor = (domain < (max_lines - 3)) ? 1 : domain / (max_lines - 3);
    int nlines = (domain < (max_lines - 3)) ? (int)domain : (max_lines - 3);

    // Output Glyphs (this is the UTF-8 required part)
    const char* none_bar = "────";
    const char* half_bar = "─▄▄▄";
    const char* full_bar = "─███";
    const char* x_axis = "─▀▀▀";
    const char* x_axis_0 = "────";
    const char* x_axis_cap = "─ ";
    const char* y_axis = "├";
    const char* line_cap = "─ ";
    const char* origin = "└";
    // const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    // Draw the graph

    // (draw everything above the X-axis)
    cout << fixed << "\n";
    for (int n = 0; n < nlines; n++) {
        double y2 = (nlines - n) * divisor;
        double y1 = y2 - divisor / 4;
        cout << setw(6) << setprecision(2) << y2 << " " << y_axis;
        for (int i = 0; i < 12; i++) {
            for (auto x : totalEachMonth[i]) {
                // change the value of x[1] to int
                x[1] = (int)x[1];
                if (x[1] > y2)
                    cout << full_bar;
                else if (x[1] > y1)
                    cout << half_bar;
                else
                    cout << none_bar;
            }
            cout << line_cap << "\n";
        }
    }

    // (draw the X-axis)
    cout << "  0.00 " << origin;
    for (int i = 0; i < 12; i++) {
        for (auto x : totalEachMonth[i]) {
            x[1] = (int)x[1];
            if (x[1] > divisor / 4)
                cout << x_axis;
            else
                cout << x_axis_0;
        }
    }
    cout << x_axis_cap << "\n";

    // (draw labels under the X-axis)
    cout << string(8, ' ');
    for (int n = 0; n < 12; n++) {
        cout << setw(3) << totalEachMonth[n][0];
    }
    cout << "\n";

    // cout << "Your spending for each category: " << endl;
    // for (int i = 0; i < 10; i++) {
    //     cout << categorySpendData[i][0] << ": RM " << categorySpendData[i][1] << endl;
    //     /*display on how much you spend on each category*/
    // }

    // cout << endl;
    // string spendMost;
    // float spendMostValue = 0;
    // for (int i = 0; i < 10; i++) {
    //     if (stof(categorySpendData[i][1]) > spendMostValue) {
    //         spendMostValue = stof(categorySpendData[i][1]);
    //         spendMost = categorySpendData[i][0];
    //     }
    // }

    // cout << "You spend the most on " << spendMost << " with RM " << spendMostValue << endl;

    cout << "\nThank you for using our program." << endl;
    system("pause");

    return 0;
}
