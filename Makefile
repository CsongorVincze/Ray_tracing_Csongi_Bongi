CC = gcc
CFLAGS = -Wall -g
OBJ = video_render.o vec_3.o sphere.o hittable.o hit_list.o render.o animation.o common.o color.o ray.o intervals.o
TARGET = video_render.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del *.o $(TARGET)
