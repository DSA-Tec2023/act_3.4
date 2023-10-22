# Makefile for a single C++ source file

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source file
SRCS = main.cpp

# Output executable name
TARGET = myprogram

# Build rule
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean rule
clean:
	rm -f $(TARGET)
	
run: $(TARGET)
	./$(TARGET)
.PHONY: clean