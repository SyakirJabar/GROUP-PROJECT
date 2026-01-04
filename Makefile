CXX = g++
CXXFLAGS = -std=c++17 -Wall

# List all your .cpp files here
SOURCES = grp-proj/main.cpp \
          grp-proj/SportsStoreProg/SportsStoreProg.cpp \
          grp-proj/SportsEquip/Ball.cpp \
          grp-proj/SportsEquip/Racket.cpp \
          grp-proj/SportsEquip/Throwable.cpp \
          grp-proj/SportsEquip/SportsEquip.cpp

# Output executable name
TARGET = storeroom

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)