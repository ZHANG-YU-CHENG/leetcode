CC:=g++
LDFLAGS+= -lgtest -lpthread #for unit test
SRC:=test_115.cpp
OBJS:=*.o
EXE:=test_115

all:
	$(CC) $(SRC) -o $(EXE) $(LDFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)