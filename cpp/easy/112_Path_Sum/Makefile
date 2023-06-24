CC:=g++
LDFLAGS+= -lgtest -lpthread #for unit test
SRC:=test_112.cpp
OBJS:=*.o
EXE:=test_112

all:
	$(CC) $(SRC) -o $(EXE) $(LDFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)