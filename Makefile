CC      = gcc
CFLAGS  = -Wall -O2 -I. $(shell pkg-config --cflags raylib)
LIBS    = $(shell pkg-config --libs raylib) -lm -ldl -lpthread

TARGET = tugas1_grafika

SRCS = main.c \
       coords.c \
       src/algo/bresellipse.c \
       src/algo/midellipse.c \
       src/algo/dda.c \
       src/algo/bresenham.c \
       src/algo/ellipse_transform.c \
       src/ui/primitives.c \
       src/ui/back_button.c \
       src/screens/tugas1_creation.c \
       src/screens/about.c \
       src/screens/menu.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

run: all
	LIBGL_ALWAYS_SOFTWARE=1 ./$(TARGET)
