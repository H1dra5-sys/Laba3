#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int year, month, daysInMonth, firstDay, startDay, currentDay, counter, dayOfWeek, yearLastTwoDigits, century, dayOfWeekCalculation;
string monthName,  months;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
  switch (month) {
    case 1: return 31;
    case 2: return isLeapYear(year) ? 29 : 28;
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
    default: return 0;
  }
}

int getFirstDayOfMonth(int month, int year) {
  if (month < 3) {
    month += 12;
    --year;
  }
yearLastTwoDigits = year % 100;
century = year / 100;
dayOfWeekCalculation = (1 + (13*(month+1))/5 + yearLastTwoDigits + yearLastTwoDigits/4 + century/4 + 5*century) % 7;
return (dayOfWeekCalculation + 5) % 7;
}

string getMonthName(int month) {
  months[] = {
    "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
  };
  return months[month - 1];
}

void printMonth(int month, int year) {
  monthName = getMonthName(month);
    
  cout << monthName << endl;
  cout << "Mon Tue Wed Thu Fri Sat Sun" << endl;
    
  daysInMonth = getDaysInMonth(month, year);
  firstDay = getFirstDayOfMonth(month, year);
  startDay = (firstDay + 5) % 7;
  currentDay = 1;
    
  for (counter = 0; counter < startDay; ++counter) {
    cout << "    ";
  }
    
  while (currentDay <= daysInMonth) {
    for (dayOfWeek = startDay; dayOfWeek < 7 && currentDay <= daysInMonth; ++dayOfWeek) {
      cout << setw(3) << currentDay << " ";
        ++currentDay;
        startDay = 0;
    }
        cout << endl;
  }
    cout << endl;
}

int main() {
  cout << "Enter year: ";
  cin >> year;
  cout << endl;
    
  for (month = 1; month <= 12; ++month) {
    printMonth(month, year);
  }
}

