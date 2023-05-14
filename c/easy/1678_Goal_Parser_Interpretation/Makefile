CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR) -g # -g for gdb debugger
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=1678_Goal_Parser_Interpretation.o test_1678.o
EXE:=test_1678

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)