CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR)
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=150_Evaluate_Reverse_Polish_Notation.o test_150.o
EXE:=test_150

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)