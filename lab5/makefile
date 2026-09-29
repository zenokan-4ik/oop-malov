CXX = g++
CXXFLAGS = -std=c++11 -I.
TARGET = tests.exe
SOURCES = CVector3D.cpp \
		tests.cpp \
		

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	del $(TARGET) 2>nul || rm -f $(TARGET)