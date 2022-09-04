CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR) -g # -g for gdb debugger
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=1051_Height_Checker.o test_1051.o
EXE:=test_1051

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)