CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR)
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=190_Reverse_Bits.o test_190.o
EXE:=test_190

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)