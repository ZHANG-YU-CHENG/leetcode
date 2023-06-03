CC:=g++
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=132_Palindrome_Partitioning_II.o test_132.o
EXE:=test_132

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $<

clean:
	rm -rf $(OBJS) $(EXE)