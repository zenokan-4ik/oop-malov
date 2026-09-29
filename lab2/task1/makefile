CXX = g++
CXXFLAGS = -std=c++11 -I.
TARGET = task.exe
SOURCES = main.cpp \
		functions.cpp \
		

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	del $(TARGET) 2>nul || rm -f $(TARGET)