CC:=g++
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=72_Edit_Distance.o test_72.o
EXE:=test_72

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $<

clean:
	rm -rf $(OBJS) $(EXE)