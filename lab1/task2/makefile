CXX = g++
CXXFLAGS = -std=c++11 -I.
TARGET = calcbits.exe
SOURCES = main.cpp \
			../modules/InputManager.cpp \
			../modules/OutputManager.cpp \

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	del $(TARGET) 2>nul || rm -f $(TARGET)