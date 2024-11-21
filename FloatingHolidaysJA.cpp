#include <iostream>
#include <string>
#include <cctype>
#include <limits>  // For numeric_limits
#include <iomanip> // for setw
using namespace std;

// Ask User for Year and Validate
int getYear()
{
    int year = 0;
    bool valid = false;

    while (!valid)
    {
        cout << "Enter the Year Between 1700 and 2100: " << endl;
        cin >> year;
        if (cin.fail() || year < 1700 || year > 2100)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n-Try Again: \n-The Year Has To Be Between 1700 and 2100\n\n";
            valid = false;
        }
        else
            return year;
    }
}

// Zeller's formula (h = (day + (13 * (month + 1)) / 5 + K + K / 4 + J / 4 - 2 * J) % 7
int calculateDay(int day, int month, int year)
{
    if (month < 3)
    {
        month += 12;
        year--;
    }
    int K = year % 100;  // Year of Century
    int J = year / 100;  // Zero based Century

    // Zeller's (and no, I did not figure out this formula myself)
    int h = (day + (13 * (month + 1)) / 5 + K + K / 4 + J / 4 - 2 * J) % 7;
    return h; // returns day for our array
}

// Calculate MLK Day
// Calculate first Monday and + 14
int getMLKDay(int year) {
    int firstDayMonth = calculateDay(1, 1, year);
    int firstMonday;
    switch (firstDayMonth)
    {
    case 1: // First Day = Monday
        firstMonday = 1;
        break;
    case 2: // First Day = Tuesday
        firstMonday = 7;
        break;
    case 3: // First Day = Wednesday
        firstMonday = 6;
        break;
    case 4: // First Day = Thursday
        firstMonday = 5;
        break;
    case 5: // First Day = Friday
        firstMonday = 4;
        break;
    case 6: // First Day = Saturday
        firstMonday = 3;
        break;
    case 0: // First Day = Sunday
        firstMonday = 2;
        break;
    }
    return firstMonday + 14; // MLK Day is the third Monday in January
}

// Calculate Presidents Day
// 3rd Monday in February (1st Feb + 14)
int getPresidentsDay(int year) {
    // get First Day February
    int firstDayMonth = calculateDay(1, 2, year);
    int firstMonday;
    switch (firstDayMonth)
    {
    case 1: // First Day = Monday
        firstMonday = 1;
        break;
    case 2: // First Day = Tuesday
        firstMonday = 7;
        break;
    case 3: // First Day = Wednesday
        firstMonday = 6;
        break;
    case 4: // First Day = Thursday
        firstMonday = 5;
        break;
    case 5: // First Day = Friday
        firstMonday = 4;
        break;
    case 6: // First Day = Saturday
        firstMonday = 3;
        break;
    case 0: // First Day = Sunday
        firstMonday = 2;
        break;
    }
    return firstMonday + 14; // Presidents Day is the third Monday in February
}

// Calculate Memorial Day
// last Monday in May ( + 14)
int getMemorialDay(int year) {
    // get Last Day May
    int lastDayMonth = 31; // 31 days in May
    int lastDayWeek = calculateDay(lastDayMonth, 5, year);
    int lastMonday;
    switch (lastDayWeek)
    {
    case 1: // Last Day = Monday
        lastMonday = 31;  // last Monday is the 31st
        break;
    case 2: // Last Day = Tuesday
        lastMonday = 30; // last Monday is the 30th
        break;
    case 3: // Last Day = Wednesday
        lastMonday = 29; // last Monday is the 29th
        break;
    case 4: // Last Day = Thursday
        lastMonday = 28; // last Monday is the 28th
        break;
    case 5: // Last Day = Friday
        lastMonday = 27; // last Monday is the 27th
        break;
    case 6: // Last Day = Saturday
        lastMonday = 26; // last Monday is the 26th
        break;
    case 0: // Last Day = Sunday
        lastMonday = 25; // last Monday is the 25th
        break;
    }
    return lastMonday; // Memorial Day is the last Monday in May
}

// Calculate Labor Day
// first Monday of September
int getLaborDay(int year)
{
    // get First Day September
    int firstDayMonth = calculateDay(1, 9, year);
    int firstMonday;
    switch (firstDayMonth)
    {
    case 1: // First Day = Monday
        firstMonday = 1;
        break;
    case 2: // First Day = Tuesday
        firstMonday = 6;
        break;
    case 3: // First Day = Wednesday
        firstMonday = 5;
        break;
    case 4: // First Day = Thursday
        firstMonday = 4;
        break;
    case 5: // First Day = Friday
        firstMonday = 3;
        break;
    case 6: // First Day = Saturday
        firstMonday = 2;
        break;
    case 0: // First Day = Sunday
        firstMonday = 1;
        break;
    }
    return firstMonday; // Labor Day is the first Monday in September
}

// Calculate Election Day
// calculate Tuesday After 1st Monday in November
int getElectionDay(int year)
{
    // get First Day November
    int firstDayNovember = calculateDay(1, 11, year);
    int firstMonday;
    switch (firstDayNovember)
    {
    case 1: // First Day = Monday
        firstMonday = 1;
        break;
    case 2: // First Day = Tuesday
        firstMonday = 6;
        break;
    case 3: // First Day = Wednesday
        firstMonday = 5;
        break;
    case 4: // First Day = Thursday
        firstMonday = 4;
        break;
    case 5: // First Day = Friday
        firstMonday = 3;
        break;
    case 6: // First Day = Saturday
        firstMonday = 2;
        break;
    case 0: // First Day = Sunday
        firstMonday = 1;
        break;
    }
    return firstMonday + 1; // Election Day is the Tuesday after the first Monday in November
}

// Calculate Thanksgiving
// calculate 4th Thursday of November
int getThanksgiving(int year)
{
    // get First Day November
    int firstDayNovember = calculateDay(1, 11, year);
    int firstThursday;
    switch (firstDayNovember)
    {
    case 1: // First Day = Monday
        firstThursday = 4;
        break;
    case 2: // First Day = Tuesday
        firstThursday = 3;
        break;
    case 3: // First Day = Wednesday
        firstThursday = 2;
        break;
    case 4: // First Day = Thursday
        firstThursday = 1;
        break;
    case 5: // First Day = Friday
        firstThursday = 7; // next Thursday
        break;
    case 6: // First Day = Saturday
        firstThursday = 6; // next Thursday
        break;
    case 0: // First Day = Sunday
        firstThursday = 5; // next Thursday
        break;
    }
    return firstThursday + 21; // Thanksgiving is the fourth Thursday in November
}

// Ask User If They Would Like To Run Again and Validate
bool askToRunAgain()
{
    char goAgain;
    bool valid = false;

    while (!valid)
    {
        cout << "\nWould you like to try again? (y/n): ";
        cin >> goAgain;

        if (cin.fail())  // Handle invalid input
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n-Try Again: \n- You Need To Enter - y or n -\n\n";
        }
        else
        {
            goAgain = toupper(goAgain);  // Convert to uppercase

            if (goAgain == 'Y')  // Check for 'Y'
            {
                valid = true;
                return true;
            }
            else if (goAgain == 'N')  // Check for 'N'
            {
                valid = true;
                return false;
            }
            else
            {
                cout << "\n-Try Again: \n- You Need To Enter - y or n -\n\n";
            }
        }
    }
    return false;  // In case something goes wrong
}

// Main Function
int main()
{
    cout << "Welcome to the Holiday Calculator!" << endl;

    do
    {
        int year = getYear();
        cout << "Year Entered: " << year << endl;

        // Align the holiday names and dates
        cout << endl;
        cout << left << setw(25) << "M L King Day " << "01" << "/" << getMLKDay(year) << "/" << year << endl;
        cout << left << setw(25) << "Presidents' Day: " << "02" << "/" <<getPresidentsDay(year) << "/" << year << endl;
        cout << left << setw(25) << "Memorial Day: " << "05" << "/" << getMemorialDay(year) << "/" << year << endl;
        cout << left << setw(25) << "Labor Day: " << "09" << "/" << getLaborDay(year) << "/" << year << endl;
        cout << left << setw(25) << "Election Day: " << "11" << "/" << getElectionDay(year) << "/" << year << endl;
        cout << left << setw(25) << "Thanksgiving: " << "11" << "/" << getThanksgiving(year) << "/" << year << endl;

    } while (askToRunAgain());

    cout << "\n you for using the Holiday Calculator! Goodbye!" << endl;
    return 0;
}
