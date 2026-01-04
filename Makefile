CXX = g++
CXXFLAGS = -std=c++17 -Wall

# List all your .cpp files here
SOURCES = grp-proj-v2/main.cpp \
          grp-proj-v2/SportsStoreProg/SportsStoreProg.cpp \
          grp-proj-v2/SportsEquip/Ball.cpp \
          grp-proj-v2/SportsEquip/Racket.cpp \
          grp-proj-v2/SportsEquip/Throwable.cpp \
          grp-proj-v2/SportsEquip/SportsEquip.cpp

# Output executable name
TARGET = storeroom

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)