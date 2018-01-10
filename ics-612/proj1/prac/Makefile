EXEC = strpbrk

all: $(EXEC)

%: %.c
	gcc -std=c11 -Wall -ggdb3 -o $@ $^
clean:
	rm -f $(EXEC)
