compile:
		gcc test.c -lgomp
run: compile
	./a.out