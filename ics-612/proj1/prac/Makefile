SRC = strpbrk.c
EXEC = strpbrk

all: $(EXEC)

%: %.c
	gcc -std=c11 -o $@ $^
clean:
	rm -f $(EXEC)
