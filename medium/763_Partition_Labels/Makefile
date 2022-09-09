CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR) -g # -g for gdb debugger
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=763_Partition_Labels.o test_763.o
EXE:=test_763

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)