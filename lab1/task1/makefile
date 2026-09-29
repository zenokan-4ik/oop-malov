CXX = g++
CXXFLAGS = -std=c++11 -I.
TARGET = copyfile.exe
SOURCES = main.cpp \
			../modules/FileManager.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	del $(TARGET) 2>nul || rm -f $(TARGET)