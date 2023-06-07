CC:=g++
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=139_Word_Break.o test_139.o
EXE:=test_139

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $<

clean:
	rm -rf $(OBJS) $(EXE)