NAME = WindowApplication 
CFLAGS = -g -Wall 
GTKFLAGS = -export-dynamic `pkg-config --cflags --libs gtk+-2.0`
SRCS = app.c
APP = -o app
CC = gcc

all: main

main: $(SRCS)
	$(CC) $(CFALGS) $(SRCS) $(APP) $(GTKFLAGS)

clean:
	rm -f $(NAME)
