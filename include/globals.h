#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>
using namespace std;

const int MAX = 500;

// AUTH
extern string systemUsername;
extern string systemPassword;

// MEMBER ARRAYS
extern int memberId[MAX];
extern string memberName[MAX];
extern string memberPhone[MAX];
extern int memberCount;

// BOOKING ARRAYS
extern int bookingId[MAX];
extern int bookingMemberId[MAX];
extern string bookingMemberName[MAX];
extern string bookingSport[MAX];
extern int bookingCount;
extern string bookingDate[MAX];
extern string bookingTime[MAX];
extern int bookingDuration[MAX];

// EQUIPMENT ARRAYS
extern int equipMemberId[MAX];
extern string equipMemberName[MAX];
extern string equipSport[MAX];
extern string equipItem[MAX];
extern bool equipReturned[MAX];
extern int equipCount;
extern bool equipDamaged[MAX];
extern int equipFine[MAX];

const int DAMAGE_FINE = 500;

// FILE NAMES
extern string MEMBER_FILE;
extern string BOOKING_FILE;
extern string EQUIP_FILE;

#endif
