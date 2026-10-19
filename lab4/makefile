CXX = g++
CXXFLAGS = -std=c++20 -I. -Isrc
TARGET = shapes.exe
TESTS = tests.exe

SOURCES = src/CCircle.cpp \
          src/CLineSegment.cpp \
          src/CParser.cpp \
          src/CPoint.cpp \
          src/CRectangle.cpp \
          src/CTriangle.cpp \
          src/App.cpp

MAIN_SOURCES = $(SOURCES) src/main.cpp
TEST_SOURCES = $(SOURCES) src/tests.cpp

all: $(TARGET)

$(TARGET): $(MAIN_SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(MAIN_SOURCES)

test: $(TESTS)
	./$(TESTS)

$(TESTS): $(TEST_SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TESTS) $(TEST_SOURCES)

clean:
	rm -f $(TARGET) $(TESTS)