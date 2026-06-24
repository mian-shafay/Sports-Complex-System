#include <iostream>
#include <fstream>
#include <iomanip>
#include "../include/globals.h"
#include "../include/members.h"
#include "../include/equipment.h"
using namespace std;

void saveEquipment()
{
    ofstream file(EQUIP_FILE);
    file << "MemberID MemberName Sport Item Returned Damaged Fine\n";
    for (int i = 0; i < equipCount; i++)
    {
        file << equipMemberId[i] << " "
             << "\"" << equipMemberName[i] << "\"" << " "
             << equipSport[i] << " "
             << equipItem[i] << " "
             << (equipReturned[i] ? 1 : 0) << " "
             << (equipDamaged[i] ? 1 : 0) << " "
             << equipFine[i] << "\n";
    }
    file.close();
}

void issueEquipment()
{
    cout << "\n===== ISSUE EQUIPMENT =====\n";
    showMembers();

    if (equipCount >= MAX)
    {
        cout << "Equipment record list full. Cannot add more.\n";
        return;
    }

    cout << "Enter Member ID: ";
    cin >> equipMemberId[equipCount];

    if (equipMemberId[equipCount] < 1 || equipMemberId[equipCount] > memberCount)
    {
        cout << "Invalid Member ID.\n";
        return;
    }

    equipMemberName[equipCount] = memberName[equipMemberId[equipCount] - 1];

    int sportChoice;
    cout << "Choose Sport:\n";
    cout << "1. Basketball\n";
    cout << "2. Badminton\n";
    cout << "3. Football\n";
    cout << "Enter choice (1-3): ";
    cin >> sportChoice;

    if (sportChoice == 1)
    {
        equipSport[equipCount] = "Basketball";
        equipItem[equipCount]  = "Basketball";
    }
    else if (sportChoice == 2)
    {
        equipSport[equipCount] = "Badminton";
        equipItem[equipCount]  = "BadmintonKit";
    }
    else if (sportChoice == 3)
    {
        equipSport[equipCount] = "Football";
        equipItem[equipCount]  = "Football";
    }
    else
    {
        cout << "Invalid sport choice.\n";
        return;
    }

    equipReturned[equipCount] = false;
    equipDamaged[equipCount]  = false;
    equipFine[equipCount]     = 0;

    equipCount++;
    saveEquipment();
    cout << "Equipment Issued.\n";
}

void returnEquipment()
{
    showMembers();
    showEquipment();
    cout << "\n===== RETURN EQUIPMENT =====\n";

    int id;
    cout << "Enter Member ID: ";
    cin >> id;

    if (id < 1 || id > memberCount)
    {
        cout << "Invalid Member ID.\n";
        return;
    }

    for (int i = 0; i < equipCount; i++)
    {
        if (equipMemberId[i] == id && !equipReturned[i])
        {
            equipReturned[i] = true;

            char damaged;
            cout << "Is the item damaged? (y/n): ";
            cin >> damaged;

            if (damaged == 'y' || damaged == 'Y')
            {
                equipDamaged[i] = true;
                equipFine[i]    = DAMAGE_FINE;
                cout << "Item marked as damaged. Fine imposed: "
                     << DAMAGE_FINE << " PKR\n";
            }
            else
            {
                equipDamaged[i] = false;
                equipFine[i]    = 0;
                cout << "Item returned in good condition.\n";
            }

            saveEquipment();
            return;
        }
    }
    cout << "No equipment found for this member or already returned.\n";
}

void showEquipment()
{
    cout << "\n===== EQUIPMENT RECORDS =====\n";
    cout << left
         << setw(15) << "MEMBER"
         << setw(20) << "ITEM"
         << setw(10) << "RETURNED"
         << setw(10) << "DAMAGED"
         << setw(10) << "FINE" << endl;
    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < equipCount; i++)
    {
        cout << left
             << setw(15) << equipMemberName[i]
             << setw(20) << equipItem[i]
             << setw(10) << (equipReturned[i] ? "Yes" : "No")
             << setw(10) << (equipDamaged[i] ? "Yes" : "No")
             << setw(10) << equipFine[i] << endl;
    }
}

void loadEquipment()
{
    ifstream file(EQUIP_FILE);
    if (!file)
        return;

    string headerLine;
    getline(file, headerLine);

    equipCount = 0;
    while (equipCount < MAX)
    {
        if (!(file >> equipMemberId[equipCount]))
            break;

        file >> ws;
        if (file.peek() == '"')
        {
            file.get();
            getline(file, equipMemberName[equipCount], '"');
        }
        else
        {
            file >> equipMemberName[equipCount];
        }

        int returnedInt = 0, damagedInt = 0;
        if (!(file >> equipSport[equipCount] >> equipItem[equipCount]
                   >> returnedInt >> damagedInt >> equipFine[equipCount]))
            break;

        equipReturned[equipCount] = (returnedInt != 0);
        equipDamaged[equipCount]  = (damagedInt  != 0);
        equipCount++;
    }
    file.close();
}
