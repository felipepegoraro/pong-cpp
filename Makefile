CC := g++
TARGET := pong
CFLAGS := -Wall -Werror -Wextra -O2
LFLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
SRC := ./src/utils.cpp ./src/game.cpp ./src/player.cpp ./src/bullet.cpp

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(TARGET).cpp $(LFLAGS)
