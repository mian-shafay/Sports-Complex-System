# Air University Sports Management System

A console-based Sports Management System written in C++. It allows an admin to manage gym/sports-facility members, court bookings, and equipment — with all data persisted to CSV files between sessions.

---

## Features

- **Login System** — Admin-only access with 3-attempt lockout
- **Member Management** — Register members and view the full member list
- **Court Bookings** — Book, view, and cancel sports slots with clash detection
- **Equipment Tracking** — Issue and return equipment; auto-apply damage fines
- **CSV Persistence** — All data is saved to and loaded from flat CSV files

---

## Supported Sports

| Sport      | Equipment Issued |
|------------|-----------------|
| Basketball | Basketball       |
| Badminton  | Badminton Kit    |
| Football   | Football         |

---

## Project Structure

```
sports-management/
├── include/
│   ├── globals.h       # Shared constants, array declarations
│   ├── auth.h
│   ├── members.h
│   ├── bookings.h
│   ├── equipment.h
│   └── menu.h
├── src/
│   ├── globals.cpp     # Global variable definitions
│   ├── auth.cpp        # Login logic
│   ├── members.cpp     # Member register / display / load / save
│   ├── bookings.cpp    # Booking create / cancel / clash-check / load / save
│   ├── equipment.cpp   # Issue / return / damage fine / load / save
│   ├── menu.cpp        # Main menu loop
│   └── main.cpp        # Entry point
├── Makefile
└── README.md
```

---

## Getting Started

### Prerequisites

- A C++11-compatible compiler (`g++` recommended)
- `make` (optional but convenient)

### Compile & Run

**Using Make:**
```bash
make
./sports_management
```

**Manually:**
```bash
g++ -std=c++11 -Iinclude -o sports_management src/*.cpp
./sports_management
```

### Default Login Credentials

| Field    | Value   |
|----------|---------|
| Username | `admin` |
| Password | `1234`  |

---

## Data Storage

The program automatically creates and reads three CSV files in the working directory:

| File            | Contents              |
|-----------------|-----------------------|
| `members.csv`   | Registered members    |
| `bookings.csv`  | Court bookings        |
| `equipment.csv` | Equipment issue log   |

---

## Damage Fine

A flat fine of **500 PKR** is applied when equipment is returned damaged.

---

## Limitations

- Maximum of **500** records per category (members, bookings, equipment)
- Clash detection is based on sport + date + exact start time
- No password hashing — credentials are stored in plain text in source code
