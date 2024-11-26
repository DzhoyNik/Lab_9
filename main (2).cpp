#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int getDayofWeek(int year) {
    int twoLastFigureYear;
    int firstDayYear;

    if (year >= 2000) {
        twoLastFigureYear = year % 100;
        firstDayYear = (6 + twoLastFigureYear + twoLastFigureYear / 4) % 7;
    }
    else {
        twoLastFigureYear = year % 100;
        firstDayYear = (6 + twoLastFigureYear + twoLastFigureYear / 4) % 7 + 1;
    }

    return firstDayYear;
}

int main() {
    setlocale(LC_ALL, "ru");

    int year;
    cout << " Введите год: ";
    cin >> year;

    if (cin.fail()) {
        cout << " Некорректный ввод. Пожалуйста, введите целое число." << endl;
        return 1;
    }

    vector <int> daysInMonth = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int startDay = getDayofWeek(year);

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        daysInMonth[2] = 29;
        startDay = startDay - 1;
    }

    cout << " Календарь для " << year << " года." << endl;

    for (int month = 1; month <= 12; ++month) {
        cout << "_________________________________" << endl;
        cout << endl;
        cout << "\033[" << 33 << "m" << "  " << (month == 1 ? "Январь" : month == 2 ? "Февраль" : month == 3 ? "Март" :
            month == 4 ? "Апрель" : month == 5 ? "Май" : month == 6 ? "Июнь" : month == 7 ? "Июль" :
            month == 8 ? "Август" : month == 9 ? "Сентябрь" : month == 10 ? "Октябрь" : month == 11 ? "Ноябрь" :
            "Декабрь") << "\033[0m" << endl;
        cout << endl;
        cout << " Пн   Вт   Ср   Чт   Пт   " << "\033[" << 31 << "m" << "Сб   Вс" << "\033[0m" << endl;

        int dayOfWeek = startDay;

        for (int i = 0; i < dayOfWeek; ++i)
            cout << "     ";

        for (int day = 1; day <= daysInMonth[month]; ++day) {
            cout << setw(3) << day << "  ";
            dayOfWeek++;
            if (dayOfWeek > 6) {
                dayOfWeek = 0;
                cout << endl;
            }
        }

        cout << endl;

        startDay = (startDay + daysInMonth[month]) % 7;
    }

    return 0;
}