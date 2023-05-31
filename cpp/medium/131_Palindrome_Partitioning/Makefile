CC:=g++
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=131_Palindrome_Partitioning.o test_131.o
EXE:=test_131

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $<

clean:
	rm -rf $(OBJS) $(EXE)