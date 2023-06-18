CC:=g++
LDFLAGS+= -lgtest -lpthread #for unit test
SRC:=test_5.cpp
OBJS:=*.o
EXE:=test_5

all:
	$(CC) $(SRC) -o $(EXE) $(LDFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)