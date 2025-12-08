CXXFLAGS = -std=c++17 -Wall -Wextra -I. -Imodel -Imodel/rules -Imodel/state -Iview -Icontroller
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system   # <-- retiré -lsfml-main

# Source files (automatic detection)
SRC = $(wildcard *.cpp) \
      $(wildcard model/*.cpp) \
      $(wildcard model/rules/*.cpp) \
      $(wildcard model/state/*.cpp) \
      $(wildcard view/*.cpp) \
      $(wildcard controller/*.cpp)

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name
EXEC = start

# Main target
all: $(EXEC)

# Link object files to create executable
$(EXEC): $(OBJ)
	g++ $(OBJ) -o $(EXEC) $(LDFLAGS)

# Compile source files to object files
%.o: %.cpp
	g++ $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(EXEC)
	rm -f *.o */*.o */*/*.o

.PHONY: all clean
