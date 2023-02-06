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
int main(int argc, char** argv) {
// Windows needs a little help...
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    // Maximum screen height
    int max_lines = (argc == 2) ? std::stoi(argv[1]) : 25;

    // Get the values to be graphed from standard input
    std::vector<double> xs;
    {
        if (isatty(0)) std::cout << "xs? ";  // Ask the user, if necessary
        double x;
        while (cin >> x)
            xs.emplace_back(x);
    }

    // Calculate the vertical dimensions of the graph,
    // fitting it to the available space as necessary.
    double domain = *std::max_element(xs.begin(), xs.end());
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
    const char* digits[] = {"₀", "₁", "₂", "₃", "₄", "₅", "₆", "₇", "₈", "₉"};

    // Draw the graph

    // (draw everything above the X-axis)
    std::cout << std::fixed << "\n";
    for (int n = 0; n < nlines; n++) {
        double y2 = (nlines - n) * divisor;
        double y1 = y2 - divisor / 4;
        std::cout << std::setw(6) << std::setprecision(2) << y2 << " " << y_axis;
        for (auto x : xs) {
            if (x > y2)
                std::cout << full_bar;
            else if (x > y1)
                std::cout << half_bar;
            else
                std::cout << none_bar;
        }
        std::cout << line_cap << "\n";
    }

    // (draw the X-axis)
    std::cout << "  0.00 " << origin;
    for (auto x : xs) {
        if (x > divisor / 4)
            std::cout << x_axis;
        else
            std::cout << x_axis_0;
    }
    std::cout << x_axis_cap << "\n";

    // (draw labels under the X-axis)
    std::cout << std::string(8, ' ');
    for (int n = 0; n < xs.size(); n++) {
        auto s = std::to_string(n);
        std::string d;
        for (auto& c : s) d += digits[c - '0'];
        std::cout << setw(3) << "x" << d;
    }
    std::cout << "\n";
}