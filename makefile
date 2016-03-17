#usage: make,or make -f file
#makefile includes rules of compling linking and so on.
#three elements: targets, prerequisites and command
#format as below
#targets:prerequisites
#[TAB]command
#only one goal taget in a makefile, and it's the first target.
#$^:all prerequisites, $@:target, $<:the first prerequisite
#@:cancel echo
makefilelearn : makefilelearn.o sum.o
	gcc -o $@ $^
sum.o : sum.c
	@gcc -o $@ -c $^
makefilelearn.o : makefilelearn.c
	@gcc -o $@ -c $^
.PHONY : clean
clean :
	rm -f makefilelearn.o sum.o makefilelearn
