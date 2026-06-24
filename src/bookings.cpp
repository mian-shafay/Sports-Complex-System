#include <iostream>
#include <fstream>
#include <iomanip>
#include "../include/globals.h"
#include "../include/members.h"
#include "../include/bookings.h"
using namespace std;

void saveBookings()
{
    ofstream file(BOOKING_FILE);
    file << "ID MEMBER SPORT DATE TIME DURATION\n";

    for (int i = 0; i < bookingCount; i++)
    {
        file << bookingId[i] << " "
             << bookingMemberId[i] << " "
             << "\"" << bookingMemberName[i] << "\"" << " "
             << bookingSport[i] << " "
             << bookingDate[i] << " "
             << bookingTime[i] << " "
             << bookingDuration[i] << "\n";
    }
    file.close();
}

bool clash(string sport, string date, string time)
{
    for (int i = 0; i < bookingCount; i++)
    {
        if (bookingSport[i] == sport &&
            bookingDate[i] == date &&
            bookingTime[i] == time)
        {
            return true;
        }
    }
    return false;
}

void createBooking()
{
    showMembers();
    cout << "\n===== CREATE BOOKING =====\n";

    int id;
    cout << "Enter Member ID: ";
    cin >> id;

    if (id < 1 || id > memberCount)
    {
        cout << "Invalid Member ID.\n";
        return;
    }

    if (bookingCount >= MAX)
    {
        cout << "Booking list full. Cannot create more.\n";
        return;
    }

    int sportChoice;
    cout << "Choose Sport:\n";
    cout << "1. Basketball\n";
    cout << "2. Badminton\n";
    cout << "3. Football\n";
    cout << "Enter choice (1-3): ";
    cin >> sportChoice;

    if (sportChoice == 1)
        bookingSport[bookingCount] = "Basketball";
    else if (sportChoice == 2)
        bookingSport[bookingCount] = "Badminton";
    else if (sportChoice == 3)
        bookingSport[bookingCount] = "Football";
    else
    {
        cout << "Invalid sport choice.\n";
        return;
    }

    cout << "Enter Date (DD-MM-YYYY): ";
    cin >> bookingDate[bookingCount];

    cout << "Enter Start Time (HH:MM): ";
    cin >> bookingTime[bookingCount];

    cout << "Enter Duration (minutes): ";
    cin >> bookingDuration[bookingCount];

    if (clash(bookingSport[bookingCount],
              bookingDate[bookingCount],
              bookingTime[bookingCount]))
    {
        cout << "This slot is already booked.\n";
        return;
    }

    bookingId[bookingCount]         = bookingCount + 1;
    bookingMemberId[bookingCount]   = id;
    bookingMemberName[bookingCount] = memberName[id - 1];

    cout << "Booking Created Successfully!\n";
    cout << "Booking ID: " << bookingId[bookingCount] << endl;

    bookingCount++;
    saveBookings();
}

void showBookings()
{
    cout << "\n===== ALL BOOKINGS =====\n";
    cout << left
         << setw(5)  << "ID"
         << setw(15) << "MEMBER"
         << setw(15) << "SPORT"
         << setw(15) << "DATE"
         << setw(10) << "TIME"
         << setw(10) << "DURATION" << endl;
    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < bookingCount; i++)
    {
        cout << left
             << setw(5)  << bookingId[i]
             << setw(15) << bookingMemberName[i]
             << setw(15) << bookingSport[i]
             << setw(15) << bookingDate[i]
             << setw(10) << bookingTime[i]
             << setw(5)  << bookingDuration[i] << "minutes" << endl;
    }
}

void cancelBooking()
{
    cout << "\n===== CANCEL BOOKING =====\n";
    showBookings();

    int id;
    cout << "Enter Booking ID: ";
    cin >> id;

    for (int i = 0; i < bookingCount; i++)
    {
        if (bookingId[i] == id)
        {
            for (int j = i; j < bookingCount - 1; j++)
            {
                bookingId[j]         = bookingId[j + 1];
                bookingMemberId[j]   = bookingMemberId[j + 1];
                bookingMemberName[j] = bookingMemberName[j + 1];
                bookingSport[j]      = bookingSport[j + 1];
                bookingDate[j]       = bookingDate[j + 1];
                bookingTime[j]       = bookingTime[j + 1];
                bookingDuration[j]   = bookingDuration[j + 1];
            }
            bookingCount--;
            saveBookings();
            cout << "Booking Cancelled.\n";
            return;
        }
    }
    cout << "Booking ID not found.\n";
}

void loadBookings()
{
    ifstream file(BOOKING_FILE);
    if (!file)
        return;

    string headerLine;
    getline(file, headerLine);

    bookingCount = 0;
    while (bookingCount < MAX)
    {
        if (!(file >> bookingId[bookingCount] >> bookingMemberId[bookingCount]))
            break;

        file >> ws;
        if (file.peek() == '"')
        {
            file.get();
            getline(file, bookingMemberName[bookingCount], '"');
        }
        else
        {
            file >> bookingMemberName[bookingCount];
        }

        if (!(file >> bookingSport[bookingCount] >> bookingDate[bookingCount]
                   >> bookingTime[bookingCount] >> bookingDuration[bookingCount]))
            break;

        bookingCount++;
    }
    file.close();
}
