# Makefile

# Compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I/opt/homebrew/include -I/opt/homebrew/opt/python@3.11/Frameworks/Python.framework/Versions/3.11/include/python3.11

# Linker flags
LDFLAGS = -L/opt/homebrew/lib -L/opt/homebrew/opt/python@3.11/Frameworks/Python.framework/Versions/3.11/lib
LDLIBS = -lboost_python312 -lpython3.11 -ldl -framework CoreFoundation

# Source files
SOURCES = main.cpp RubiksCube.cpp CubeControllerModule.cpp

OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = rubiksSolver

# Default target
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

# To obtain object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# To remove generated files
clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
