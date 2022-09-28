CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR) -g -Wall # -g : gdb debugger, -Wall : show all warning message
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=1720_Decode_XORed_Array.o test_1720.o
EXE:=test_1720

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)