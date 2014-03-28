CC = gcc
TARGET = gametest
OBJS = test.o
CFLAGS += `pkg-config --cflags gtk+-2.0`
LDFLAGS += `pkg-config --libs gtk+-2.0`

$(TARGET):$(OBJS)
	$(CC) $^ -W -o $@ $(CFLGAS) $(LDFLAGS)


