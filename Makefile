CC = gcc
CFLAGS = -DDEBUG -Wall -g

TARGET = game_board player_turns main common

OBJS = game_board.o player_turns.o main.o

all: $(TARGET)

$(TARGET): $(OBJS)
			$(CC) $(LDFLAGS) -o $@ $^

$(OBJS): %.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f *.o