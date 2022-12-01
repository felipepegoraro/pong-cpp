CC := g++
TARGET := pong
CFLAGS := -Wall -Werror -Wextra -O2
LFLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
# SRC :=

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(LFLAGS)
