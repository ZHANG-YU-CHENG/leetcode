CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR) -g # -g for gdb debugger
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=349_Intersection_of_Two_Arrays.o test_349.o
EXE:=test_349

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)