#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int d, m, y;
    time_t now = time(0);
    cout << "Our birhtday day:\n";
    cin >> d;
    cout << "Our birhtday month:\n";
    cin >> m;
    cout << "Our birhtday year:\n";
    cin >> y;

    tm *ltm = localtime(&now);

    int day = ltm->tm_mday - d;
    int month = 1 + ltm->tm_mon - m;
    int year = 1900 + ltm->tm_year - y;

    if (day < 0){
        day += d;
    cout << "Day: "<< day << endl;
    }

    if (month < 0)
    {
        month += 12;
        year--;
    }

    cout << "Month: "<< month << endl;
    cout << "Year: " << year <<endl;
}
