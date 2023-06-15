CC:=g++
LDFLAGS+= -lgtest -lpthread #for unit test, -std=c++11
SRC:=test_23.cpp
OBJS:=*.o
EXE:=test_23

all:
	$(CC) $(SRC) -o $(EXE) $(LDFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)