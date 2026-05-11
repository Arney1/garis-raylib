CC     = gcc
CFLAGS = -Wall -O2 -I. $(shell pkg-config --cflags raylib)
LIBS   = $(shell pkg-config --libs raylib) -lm -ldl -lpthread

TARGET = grafika_dda

SRCS = main.c \
       coords.c \
       src/algo/dda.c \
       src/algo/bresenham.c \
       src/algo/midcircle.c \
       src/ui/primitives.c \
       src/ui/back_button.c \
       src/ui/cartesian.c \
       src/screens/program1.c \
       src/screens/program2.c \
       src/screens/program3.c \
       src/screens/program4.c \
       src/screens/program5.c \
       src/screens/program6.c \
       src/screens/program7.c \
       src/screens/program8.c \
       src/screens/program9.c \
       src/screens/tugas1_1.c \
       src/screens/tugas1_2.c \
       src/screens/tugas1_3.c \
       src/screens/tugas2_1.c \
       src/screens/tugas2_2.c \
       src/screens/tugas2_3.c \
       src/screens/tugas3_1.c \
       src/screens/tugas3_2.c \
       src/screens/tugas3_3.c \
       src/screens/tugas4_1.c \
       src/screens/tugas4_2.c \
       src/screens/tugas4_3.c \
       src/screens/tugas5_1.c \
       src/screens/tugas5_2.c \
       src/screens/tugas5_3.c \
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
