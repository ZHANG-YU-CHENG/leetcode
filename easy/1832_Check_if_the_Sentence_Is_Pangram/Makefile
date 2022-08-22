CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR) -g # -g for gdb debugger
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=1832_Check_if_the_Sentence_Is_Pangram.o test_1832.o
EXE:=test_1832

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)