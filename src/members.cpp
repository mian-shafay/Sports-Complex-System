#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include "../include/globals.h"
#include "../include/members.h"
using namespace std;

void saveMembers()
{
    ofstream file(MEMBER_FILE);
    file << "ID NAME PHONE\n";
    for (int i = 0; i < memberCount; i++)
    {
        file << memberId[i] << " "
             << "\"" << memberName[i] << "\"" << " "
             << memberPhone[i] << "\n";
    }
    file.close();
}

void registerMember()
{
    cout << "\n===== REGISTER MEMBER =====\n";
    if (memberCount >= MAX)
    {
        cout << "Member list full. Cannot add more.\n";
        return;
    }

    memberId[memberCount] = memberCount + 1;

    cout << "Enter Name  : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, memberName[memberCount]);

    cout << "Enter Phone : ";
    cin >> memberPhone[memberCount];

    cout << "Member ID Assigned: " << memberId[memberCount] << endl;

    memberCount++;
    saveMembers();
}

void showMembers()
{
    cout << "\n===== ALL MEMBERS =====\n";
    cout << left
         << setw(5)  << "ID"
         << setw(20) << "NAME"
         << setw(15) << "PHONE" << endl;
    cout << "------------------------------------------\n";

    for (int i = 0; i < memberCount; i++)
    {
        cout << left
             << setw(5)  << memberId[i]
             << setw(20) << memberName[i]
             << setw(15) << memberPhone[i] << endl;
    }
}

void loadMembers()
{
    ifstream file(MEMBER_FILE);
    if (!file)
        return;

    string temp;
    file >> temp >> temp >> temp; // skip header

    memberCount = 0;
    while (file >> memberId[memberCount])
    {
        file >> ws;
        getline(file, memberName[memberCount], '"'); // skip until first quote
        getline(file, memberName[memberCount], '"'); // read inside quotes
        file >> memberPhone[memberCount];
        memberCount++;
    }
    file.close();
}
