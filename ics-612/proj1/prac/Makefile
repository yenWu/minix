EXEC = strpbrk fork_execvp

all: $(EXEC)

%: %.c
	gcc -std=c11 -Wall -ggdb3 -o $@ $^
clean:
	rm -f $(EXEC)
