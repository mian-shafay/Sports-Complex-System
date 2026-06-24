#include <string>
#include "../include/globals.h"
using namespace std;

string systemUsername = "admin";
string systemPassword = "1234";

// MEMBER ARRAYS
int memberId[MAX];
string memberName[MAX];
string memberPhone[MAX];
int memberCount = 0;

// BOOKING ARRAYS
int bookingId[MAX];
int bookingMemberId[MAX];
string bookingMemberName[MAX];
string bookingSport[MAX];
int bookingCount = 0;
string bookingDate[MAX];
string bookingTime[MAX];
int bookingDuration[MAX];

// EQUIPMENT ARRAYS
int equipMemberId[MAX];
string equipMemberName[MAX];
string equipSport[MAX];
string equipItem[MAX];
bool equipReturned[MAX];
int equipCount = 0;
bool equipDamaged[MAX];
int equipFine[MAX];

// FILE NAMES
string MEMBER_FILE  = "members.csv";
string BOOKING_FILE = "bookings.csv";
string EQUIP_FILE   = "equipment.csv";
