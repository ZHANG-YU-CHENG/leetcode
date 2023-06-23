CC:=g++
LDFLAGS+= -lgtest -lpthread #for unit test
SRC:=test_543.cpp
OBJS:=*.o
EXE:=test_543

all:
	$(CC) $(SRC) -o $(EXE) $(LDFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)