Objects=foo.o bar.o
CFLAGS:=-Wall

%.x:CFLAGS += -g
%.o:CFLAGS += -O2

%.x %.o : %.c
	$(CC) $(CFLAGS) $< -o $@
#foo.o foo.x : foo.c
#	$(CC) $(CFLAGS) $< -o $@
