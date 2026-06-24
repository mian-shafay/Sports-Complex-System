CXX      = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude
TARGET   = sports_management
SRCDIR   = src

SRCS = $(SRCDIR)/globals.cpp \
       $(SRCDIR)/members.cpp \
       $(SRCDIR)/bookings.cpp \
       $(SRCDIR)/equipment.cpp \
       $(SRCDIR)/auth.cpp \
       $(SRCDIR)/menu.cpp \
       $(SRCDIR)/main.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
