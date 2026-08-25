CXX      := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -g

TARGET   := program.exe

SRCS     := 03_main.cpp 03_math.cpp
OBJS     := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean

clean:
	del /f /q $(OBJS) $(TARGET)