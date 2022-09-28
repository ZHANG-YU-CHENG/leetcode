CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR) -g -Wall # -g : gdb debugger, -Wall : show all warning message
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=2220_Minimum_Bit_Flips_to_Convert_Number.o test_2220.o
EXE:=test_2220

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)