CC = gcc
CFLAGS = -Wall -g
TARGET = main
SRCS = Main.c commands.c read_file.c
OBJS = $(SRCS:.c=.o)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean the build directory
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)