CC:=g++
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=63_Unique_Paths_II.o test_63.o
EXE:=test_63

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $<

clean:
	rm -rf $(OBJS) $(EXE)