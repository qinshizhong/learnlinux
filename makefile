#usage: make,or make -f file
#makefile includes rules of compling linking and so on.
#three elements: targets, prerequisites and command
#format as below
#targets:prerequisites
#[TAB]command
#only one goal taget in a makefile, and it's the first target.
#$^:all prerequisites, $@:target, $<:the first prerequisite
#@:cancel echo

CC = gcc
CFLAGS = -Wall -O -g
OBJECTS = makefilelearn.o sum.o

makefilelearn : $(OBJECTS)
	$(CC) -o $@ $^
$(OBJECTS) : %.o : %.c
	@echo compiling $<
	$(CC) $(CFLAGS) -o $@ -c $<
#sum.o : sum.c sum.h
#	@$(CC) $(CFLAGS) -o $@ -c $<
#makefilelearn.o : makefilelearn.c
#	@$(CC) $(CFLAGS) -o $@ -c $^
.PHONY : clean
clean :
	rm -f makefilelearn.o sum.o makefilelearn
