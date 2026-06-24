#include "../include/auth.h"
#include "../include/members.h"
#include "../include/bookings.h"
#include "../include/equipment.h"
#include "../include/menu.h"

void loadAll()
{
    loadMembers();
    loadBookings();
    loadEquipment();
}

int main()
{
    loadAll();
    if (login())
    {
        menu();
    }
    return 0;
}
