CC:=g++
LDFLAGS+= -lgtest -lpthread #for unit test
SRC:=test_144.cpp
OBJS:=*.o
EXE:=test_144

all:
	$(CC) $(SRC) -o $(EXE) $(LDFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)