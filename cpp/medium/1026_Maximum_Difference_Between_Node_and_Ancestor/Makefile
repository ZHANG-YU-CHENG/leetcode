CC:=g++
LDFLAGS+= -lgtest -lpthread #for unit test
SRC:=test_1026.cpp
OBJS:=*.o
EXE:=test_1026

all:
	$(CC) $(SRC) -o $(EXE) $(LDFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)