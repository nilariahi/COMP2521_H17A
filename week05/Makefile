CC = clang
CFLAGS = -Wall -Wvla -Werror -g

##############################################################################

asan: CFLAGS += -fsanitize=address,leak,undefined
asan: all

msan: CFLAGS += -fsanitize=memory,undefined -fsanitize-memory-track-origins
msan: all

nosan: all

##############################################################################

all: style

style: style.c
	$(CC) $(CFLAGS) -o style style.c

##############################################################################

clean:
	rm -f style
