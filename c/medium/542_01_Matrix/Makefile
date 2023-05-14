CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR)
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=542_01_Matrix.o test_542.o
EXE:=test_542

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)