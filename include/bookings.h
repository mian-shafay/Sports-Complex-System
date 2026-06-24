#ifndef BOOKINGS_H
#define BOOKINGS_H

#include <string>
using namespace std;

void saveBookings();
bool clash(string sport, string date, string time);
void createBooking();
void showBookings();
void cancelBooking();
void loadBookings();

#endif
