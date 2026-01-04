CXX = g++
CXXFLAGS = -std=c++17 -Wall

# List all your .cpp files here
SOURCES = grp-proj-v3/main.cpp \
          grp-proj-v3/SportsStoreProg/SportsStoreProg.cpp \
          grp-proj-v3/SportsEquip/Ball.cpp \
          grp-proj-v3/SportsEquip/Racket.cpp \
          grp-proj-v3/SportsEquip/Throwable.cpp \
          grp-proj-v3/SportsEquip/Stick.cpp \
          grp-proj-v3/SportsEquip/Helmet.cpp \
          grp-proj-v3/SportsEquip/SportsEquip.cpp

# Output executable name
TARGET = storeroom

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)