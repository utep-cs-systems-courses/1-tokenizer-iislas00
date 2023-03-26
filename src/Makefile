OBJS = tokenizer.o uimain.o history.o
CFLAGS = -g -O3
all: tokenizer
tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)
clean:
	rm -f *.o *.c~
run: tokenizer
	./tokenizer
