CC = g++

# Debug
CFLAGS = -ggdb -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -std=c++20

# Release
# CFLAGS = -O2 -DNDEBUG -std=c++20

TARGET = anagrams

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	$(RM) $(TARGET) $(TARGET).txt

run: $(TARGET)
	./$(TARGET)
