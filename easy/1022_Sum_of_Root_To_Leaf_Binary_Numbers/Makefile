CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR) -g -Wall # -g : gdb debugger, -Wall : show all warning message
LIB_DIR:=../../shared_libraries/binary_tree_utils
LDFLAGS:=-L$(LIB_DIR) -Wl,-rpath=$(LIB_DIR) -lbinary_tree_utils
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=1022_Sum_of_Root_To_Leaf_Binary_Numbers.o test_1022.o
EXE:=test_1022

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)