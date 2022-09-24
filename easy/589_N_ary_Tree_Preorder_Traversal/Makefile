CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR) -g -Wall # -g : gdb debugger, -Wall : show all warning message
LIB_DIR:=../../shared_libraries/binary_tree_utils
LDFLAGS:=-L$(LIB_DIR) -Wl,-rpath=$(LIB_DIR) -lbinary_tree_utils
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=589_N_ary_Tree_Preorder_Traversal.o test_589.o
EXE:=test_589

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)