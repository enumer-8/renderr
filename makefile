CC			= gcc
CFLAGS		= -Wall
LDFLAGS		= -lm -lX11

all: clean renderr

clean:
	rm -f BUILD/*.bin

renderr:
	$(CC) $(CFLAGS) SRC/*.c $(LDFLAGS) -o BUILD/$@.bin
