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
    cout << " ������� ���: ";
    cin >> year;

    if (cin.fail()) {
        cout << " ������������ ����. ����������, ������� ����� �����." << endl;
        return 1;
    }

    vector <int> daysInMonth = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int startDay = getDayofWeek(year);

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        daysInMonth[2] = 29;
        startDay = startDay - 1;
    }

    cout << " ��������� ��� " << year << " ����." << endl;

    for (int month = 1; month <= 12; ++month) {
        cout << "_________________________________" << endl;
        cout << endl;
        cout << "\033[" << 33 << "m" << "  " << (month == 1 ? "������" : month == 2 ? "�������" : month == 3 ? "����" :
            month == 4 ? "������" : month == 5 ? "���" : month == 6 ? "����" : month == 7 ? "����" :
            month == 8 ? "������" : month == 9 ? "��������" : month == 10 ? "�������" : month == 11 ? "������" :
            "�������") << "\033[0m" << endl;
        cout << endl;
        cout << " ��   ��   ��   ��   ��   " << "\033[" << 31 << "m" << "��   ��" << "\033[0m" << endl;

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