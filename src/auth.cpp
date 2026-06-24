#include <iostream>
#include "../include/globals.h"
#include "../include/auth.h"
using namespace std;

bool login()
{
    string user, pass;
    int attempts = 3;

    while (attempts > 0)
    {
        cout << "\n===== LOGIN =====\n";
        cout << "Username: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;

        if (user == systemUsername && pass == systemPassword)
        {
            cout << "\nLogin Successful!\n";
            return true;
        }
        else
        {
            attempts--;
            cout << "Invalid credentials. Attempts left: " << attempts << endl;
        }
    }

    cout << "\nToo many failed attempts.\n";
    return false;
}
