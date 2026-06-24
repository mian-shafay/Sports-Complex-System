#include <iostream>
#include "../include/menu.h"
#include "../include/members.h"
#include "../include/bookings.h"
#include "../include/equipment.h"
using namespace std;

void menu()
{
    int choice;
    do
    {
        cout << "\n===== Air University SPORTS MANAGEMENT SYSTEM =====\n";
        cout << "1. Register Member\n";
        cout << "2. Show Members\n";
        cout << "3. Create Booking\n";
        cout << "4. Show Bookings\n";
        cout << "5. Cancel Booking\n";
        cout << "6. Issue Equipment\n";
        cout << "7. Return Equipment\n";
        cout << "8. Show Equipment Records\n";
        cout << "9. Exit\n";
        cout << "Choose Option: ";
        cin >> choice;

        switch (choice)
        {
        case 1: registerMember();  break;
        case 2: showMembers();     break;
        case 3: createBooking();   break;
        case 4: showBookings();    break;
        case 5: cancelBooking();   break;
        case 6: issueEquipment();  break;
        case 7: returnEquipment(); break;
        case 8: showEquipment();   break;
        case 9: cout << "Program Ended.\n"; break;
        default: cout << "Invalid Choice!\n";
        }

    } while (choice != 9);
}
