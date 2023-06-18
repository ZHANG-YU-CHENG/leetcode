CC:=g++
LDFLAGS+= -lgtest -lpthread #for unit test, -std=c++11
SRC:=test_876.cpp
OBJS:=*.o
EXE:=test_876

all:
	$(CC) $(SRC) -o $(EXE) $(LDFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)